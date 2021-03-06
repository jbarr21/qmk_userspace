#!/usr/bin/env python3
import os
import re
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from sys import argv
from textwrap import dedent
import urllib.parse

# KLE JSON for a 3x6+3
KLE_LAYOUT = dedent('''
    [{a:7,f:3},{y:0.3},"","",{y:-0.2},"",{y:-0.1},"",{y:0.1},"",{y:0.2},"",{x:3},"",{y:-0.1},"",{y:-0.1},"",{y:0.1},"",{y:0.2},"","",{y:-0.4}],
    [{y:0.3},"","",{y:-0.2},"",{y:-0.1},"",{y:0.1},"",{y:0.2},"",{x:3},"",{y:-0.1},"",{y:-0.1},"",{y:0.1},"",{y:0.2},"","",{y:-0.4}],
    [{y:0.3},"","",{y:-0.2},"",{y:-0.1},"",{y:0.1},"",{y:0.2},"",{x:3},"",{y:-0.1},"",{y:-0.1},"",{y:0.1},"",{y:0.2},"",""],
    [{x:4,y:0.5},"","",{h:1.5,y:-0.5},"",{x:1},{h:1.5},"",{y:0.5},"",""],
''')

MODS = ['GUI', 'SFT', 'ALT', 'CTL']
kle_chars_needing_escaping = [';', '/', '@', '&', '_', '=']
qmk_to_name = {
    'NO':   '',
    'ENT':  '⏎',
    'ESC':  'Esc',
    'BSPC': '⌫',
    'TAB':  'Tab',
    'SPC':  'Space',
    'MIN':  '-',
    'MINS': '-',
    'EQL': 	'=',
    'LBRC': '[',
    'RBRC': ']',
    'BSLS': '\\',
    'SCLN': ';',
    'QUOT': '\'',
    'DQUO': '"',
    'QUES': '?',
    'GRV': 	'`',
    'DOT':  '.',
    'COMM': ',',
    'SLSH': '/',
    'TILD':	'~',
    'EXLM':	'!',
    'AT':   '@',
    'HASH':	'#',
    'DLR':  '$',
    'PERC':	'%',
    'CIRC':	'^',
    'AMPR':	'&',
    'ASTR':	'*',
    'LPRN':	'(',
    'RPRN':	')',
    'UNDS':	'_',
    'PLUS':	'+',
    'LCB':  '{',
    'RCB':  '}',
    'LCBR':	'{',
    'RCBR':	'}',
    'PIPE':	'|',
    'COLN':	':',
    'LT':   '<',
    'GT':   '>',
    'UP':   '↑',
    'DOWN': '↓',
    'LEFT': '←',
    'RGHT': '→',
    'GUI':  '⌘',
    'SFT':  '⇧',
    'ALT':  '⌥',
    'CTL':  '⎈',
    'MPLY': '▶',
    'MSTP': '■',
    'MPRV': '|◀',
    'MNXT': '▶|',
    'CAPSWRD': 'CAPS WORD',
    'LLOCK': 'LAYER LOCK'
}

class Key:
    def __init__(self, code, aliases):
        aliased = aliases.get(code, code)
        code = code.replace('KC_', '').replace('XXXXXXX', '')
        if '_T(' in aliased:
            tap = aliased[aliased.find('_T(')+3+3:len(aliased)-1]
            self.tap = qmk_to_name.get(tap, tap)
            hold = aliased[1:4]
            self.hold = qmk_to_name.get(hold, hold)
        elif 'LT(' in aliased:
            comma_index = aliased.find(',')
            tap = aliased[comma_index+1:aliased.find(')')].replace('KC_', '')
            self.tap = qmk_to_name.get(tap, tap)
            self.hold = aliased[aliased.find('(')+1:comma_index]
        elif 'OSM' in aliased:
            tap = aliased[aliased.find('_')+1:len(aliased)-1]
            if tap[0] == 'L' or tap[0] == 'R':
                tap = tap[1:]
            self.tap = f"{qmk_to_name.get(tap, tap)}<br>OSM"
            self.hold = None
        elif aliased.startswith('TO(') or aliased.startswith('MO('):
            self.tap = aliased.replace('(', ' ').replace(')', '')
            self.hold = None
        elif aliased.startswith('OSL('):
            self.tap = aliased.replace('(', ' ').replace(')', '')
            self.hold = None
        elif any([code.startswith(f"{mod}_") for mod in MODS]):
            tap = code.split('_')[1]
            hold = code.split('_')[0]
            self.tap = qmk_to_name.get(tap, tap)
            self.hold = qmk_to_name.get(hold, hold)
        else:
            self.tap = qmk_to_name.get(code, code.replace('_', ' '))
            self.hold = None

    def label(self, encoded=False):
        label = self.tap
        if encoded:
            if label in kle_chars_needing_escaping:
                label = '/' + label

        if self.hold is not None:
            label += f"\n\n\n\n{self.hold}"

        if not encoded:
            label = label.replace('\\', '\\\\').replace('\n', '\\n')
 
        return urllib.parse.quote(label).replace('/', '%2F') if encoded else label


class Layer:
    Key = re.compile(r'\S{2,}(?=[,$\n])')
    
    def __init__(self, data, aliases):
        self.name = re.search(r'(?<=#define\s\_)[A-Z]+', data).group()
        self.keys = []
        for key in Layer.Key.finditer(data):
            self.keys += [Key(key.group(), aliases)]

    def to_kle(self, encoded=False):
        header = '''[{d:true,w:5,a:6,f:5}, %s],''' % (f"={self.name}" if encoded else f"\"{self.name}\"")
        data = f"{header}\n{KLE_LAYOUT.strip()}"
        if encoded:
            data = self.kle_encode(data)
        return self.add_keys(data, '""', [key.label(encoded=encoded) for key in self.keys], encoded)

    def to_kle_url(self):
        return self.to_kle(encoded=True).replace('\n', '')

    def add_keys(self, text, target, replacements, encoded):
        item = 0
        index = text.find('""', 0)
        while index >= 0:
            try:
                if encoded:
                    text = text[:index] + '=' + replacements[item] + text[index+2:]
                else:
                    text = text[:index+1] + replacements[item] + text[index+1:]
            except Exception as ex:
                exit(str(ex) + f" index={index}, textLen={len(text)}, text={text}")
            index = text.find('""', index+1)
            item+=1
        return text

    def kle_encode(self, text):
        semicolon = urllib.parse.quote(';')
        chars = {
            ',': '&',
            '[': '@',
            '{': '_',
            '}': semicolon,
            ']': semicolon,
            ' ':'',
        }
        for k, v in chars.items():
            text = text.replace(k, v)
        return text

class Layout:
    Layer = re.compile(r'#define\s+\_[A-Z]+\s+\\.+?(?:^$|\Z)', re.DOTALL | re.MULTILINE)
    Alias = re.compile(r'(?<=#define )((?:\w|_)+)\s+(.+\(.+\).*)')

    def __init__(self, file):
        self.layers = []
        self.aliases = {}
        with open(file, 'r') as f:
            text = f.read()
            for alias in Layout.Alias.finditer(text):
                self.aliases[alias.group(1)] = alias.group(2)

            for layer in Layout.Layer.finditer(text):
                self.layers += [Layer(layer.group(), self.aliases)]
    
    def to_kle(self):
        return '\n'.join([layer.to_kle() for layer in self.layers])

    def to_kle_url(self):
        layer_urls = ''.join([layer.to_kle_url() for layer in self.layers])
        return f"http://www.keyboard-layout-editor.com/##@{layer_urls}=undefined"

def save_image(url):
    download_dir = os.environ.get('GITHUB_WORKSPACE', os.environ.get('HOME')+'/Downloads')
    options = webdriver.ChromeOptions()
    options.add_argument('--headless')
    options.add_experimental_option("prefs", {
        "download.default_directory": download_dir,
        "download.prompt_for_download": False,
        "download.directory_upgrade": True,
        "safebrowsing_for_trusted_sources_enabled": False,
        "safebrowsing.enabled": False
    })
    driver = webdriver.Chrome(options=options)

    driver.get(url)
    driver.find_elements(by=By.CLASS_NAME, value='btn-success')[2].click()
    driver.find_elements(by=By.CLASS_NAME, value='dropdown-menu')[5].find_elements(by=By.TAG_NAME, value='a')[1].click()

    download_wait(download_dir, 30)

def download_wait(directory, timeout, nfiles=None):
    seconds = 0
    dl_wait = True
    while dl_wait and seconds < timeout:
        time.sleep(1)
        dl_wait = False
        files = os.listdir(directory)
        if nfiles and len(files) != nfiles:
            dl_wait = True

        for fname in files:
            if fname.endswith('.crdownload'):
                dl_wait = True

        seconds += 1
    return seconds

if __name__ == '__main__':

    if len(argv) < 2 or len(argv) > 4 or argv[len(argv)-1].startswith('-'):
        exit("Usage: ./qmk2kle.py [-l] [-i] <filename>")

    link_only = '-l' in argv

    try:
        layout = Layout(argv[len(argv)-1])
        if link_only:
            print(layout.to_kle_url())
        else:
            print(layout.to_kle())

        if '-i' in argv:
            save_image(layout.to_kle_url())

    except Exception as ex:
        exit(str(ex))

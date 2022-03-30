#include "jbarr21.h"
#include "features/caps_word.h"
#include "features/layer_lock.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    
    if (record->event.pressed) {
        process_caps_word(keycode, record, CAPSWRD);
    }

    return true;
}

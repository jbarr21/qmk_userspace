#include QMK_KEYBOARD_H
#include "tap_dance.h"
#include "layer_lock.h"

#if !defined(__ASSEMBLER__) 

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[7];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(LGUI(KC_SPACE)));
        tap_code16(LCTL(LGUI(KC_SPACE)));
        tap_code16(LCTL(LGUI(KC_SPACE)));
    }
    if(state->count > 3) {
        tap_code16(LCTL(LGUI(KC_SPACE)));
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(LGUI(KC_SPACE))); break;
        case SINGLE_HOLD: layer_on(3); break;
        case DOUBLE_TAP: register_code16(LCTL(LGUI(KC_SPACE))); register_code16(LCTL(LGUI(KC_SPACE))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(LGUI(KC_SPACE))); register_code16(LCTL(LGUI(KC_SPACE)));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(LGUI(KC_SPACE))); break;
        case SINGLE_HOLD: if (!is_layer_locked(3)) layer_off(3); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LGUI(KC_SPACE))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(LGUI(KC_SPACE))); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_SPACE));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD: layer_on(6); break;
        case DOUBLE_TAP: register_code16(LALT(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD: if (!is_layer_locked(6)) layer_off(6); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
    }
    dance_state[1].step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LABK);
        tap_code16(KC_LABK);
        tap_code16(KC_LABK);
    }
    if(state->count > 3) {
        tap_code16(KC_LABK);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_LABK); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(KC_LABK); register_code16(KC_LABK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LABK); register_code16(KC_LABK);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_LABK); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_LABK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LABK); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RABK);
        tap_code16(KC_RABK);
        tap_code16(KC_RABK);
    }
    if(state->count > 3) {
        tap_code16(KC_RABK);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_RABK); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_RABK); register_code16(KC_RABK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RABK); register_code16(KC_RABK);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_RABK); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_RABK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RABK); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_LBRACKET));
        tap_code16(LSFT(KC_LBRACKET));
        tap_code16(LSFT(KC_LBRACKET));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_LBRACKET));
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_LBRACKET)); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_LBRACKET)); register_code16(LSFT(KC_LBRACKET)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_LBRACKET)); register_code16(LSFT(KC_LBRACKET));
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_LBRACKET)); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_LBRACKET)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_LBRACKET)); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_RBRACKET));
        tap_code16(LSFT(KC_RBRACKET));
        tap_code16(LSFT(KC_RBRACKET));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_RBRACKET));
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_RBRACKET)); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_RBRACKET)); register_code16(LSFT(KC_RBRACKET)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_RBRACKET)); register_code16(LSFT(KC_RBRACKET));
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_RBRACKET)); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_RBRACKET)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_RBRACKET)); break;
    }
    dance_state[6].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
};

#endif
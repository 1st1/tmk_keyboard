#include "action.h"
#include "actionmap.h"
#include "hook.h"
#include "fc660c.h"


#define AC_L3       ACTION_LAYER_MOMENTARY(1)
#define AC_L4       ACTION_LAYER_MOMENTARY(3)
#define AC_TGL1     ACTION_LAYER_TOGGLE(2)

// emulates FC660C default keymap
#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = KMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,UP,
        L3,LALT,LGUI,          SPC,                     RGUI,RALT,L3,  LEFT,DOWN,RGHT
    ),
    [1] = KMAP(  /* FN pressed down */
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, BSPC,     PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
        TGL1,VOLD,VOLU,MUTE,F,   G,   H,   J,   K,   L,   SCLN,GRV,      ENT,
        LSFT,MPRV,MNXT,MPLY,V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,PGUP,
        L3,LALT,LGUI,          SPC,                     RGUI,RALT,L3,  HOME,PGDN,END
    ),
    [2] = KMAP(  /* FN+Ctrl layer */
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, BSPC,     PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,UP,
        L4,LALT,LGUI,          SPC,                     RGUI,RALT,L4,  LEFT,DOWN,RGHT
    ),
    [3] = KMAP(  /* FN+Ctrl layer with FN down */
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGDN,
        TGL1,VOLD,VOLU,MUTE,F,   G,   H,   J,   K,   L,   SCLN,GRV,      ENT,
        LSFT,MPRV,MNXT,MPLY,V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,PGUP,
        L4,LALT,LGUI,          SPC,                     RGUI,RALT,L4,  HOME,PGDN,END
    ),

};


void hook_layer_change(uint32_t layer_state)
{
    // lights LED on CAPSLOCK when layer 2 is enabled
    if (layer_state & (1L<<2)) {
        PORTB &= ~(1<<6);
    } else {
        PORTB |=  (1<<6);
    }
}

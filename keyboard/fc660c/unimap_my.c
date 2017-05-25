#include "action.h"
#include "actionmap.h"
#include "hook.h"
#include "fc660c.h"


#define AC_L3       ACTION_LAYER_MOMENTARY(2)
#define AC_L4       ACTION_LAYER_MOMENTARY(3)
#define AC_TGL1     ACTION_LAYER_TOGGLE(1)

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
    [1] = KMAP( /* HHKB */
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV,      PGUP,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,     PGDN,
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,L4,
        L4,LALT,LGUI,          SPC,                     RGUI,RALT,L4,  NO,NO,NO
    ),
    [2] = KMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TGL1,
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,TRNS,GRV,     TRNS,
        TRNS,MPRV,MNXT,MPLY,TRNS,TRNS,TRNS,TRNS,END, PGDN,TRNS,          TRNS,PGUP,
        L3,TRNS,TRNS,          TRNS,                    TRNS,TRNS, L3,  HOME,PGDN,END
    ),
    [3] = KMAP( /* HHKB + FN */
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TGL1,
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,UP,TRNS,TRNS,       TRNS,
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,LEFT,RGHT,     TRNS,
        TRNS,MPRV,MNXT,MPLY,TRNS,TRNS,TRNS,TRNS,END, PGDN,DOWN,          TRNS,L4,
        L4,TRNS,TRNS,          TRNS,                    TRNS,TRNS, L4,  NO,NO,NO
    ),
};


void hook_layer_change(uint32_t layer_state)
{
    // lights LED on Insert when layer 1 is enabled
    if (layer_state & (1L<<1)) {
        PORTB &= ~(1<<5);
    } else {
        PORTB |=  (1<<5);
    }
}

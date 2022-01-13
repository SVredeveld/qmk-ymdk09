#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUMPAD 1
#define _MUSIC 2
#define _ARROWS 3
#define _ARROWS2 4
//#define _RGB 
#define SAT 255
#define VAL 60

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
		KC_KP_7, KC_KP_8, KC_KP_9,
		KC_KP_4, KC_KP_5, KC_KP_6,
		KC_KP_1, KC_KP_2, LT(_NUMPAD, KC_KP_3)),

  [_NUMPAD] = LAYOUT(	
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, TG(_ARROWS), KC_TRNS, 
		TG(_MUSIC), KC_KP_0, KC_TRNS),

	[_MUSIC] = LAYOUT(
		KC_TRNS, KC_AUDIO_VOL_UP, TO(_BASE), 
		KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, 
		KC_TRNS, KC_AUDIO_VOL_DOWN, LT(_NUMPAD, KC_TRNS)),

  [_ARROWS] = LAYOUT(	
		TO(_MUSIC), KC_TRNS, TO(_BASE), 
		KC_DELETE, KC_UP, KC_TRNS, 
		KC_LEFT, LT(_ARROWS2, KC_DOWN), KC_RIGHT),

	[_ARROWS2] = LAYOUT(	
		TO(_MUSIC), KC_TRNS, TO(_BASE), 
		KC_DELETE, KC_TRNS, KC_TRNS, 
		KC_HOME, KC_TRNS, KC_END),
  // [_RGB] = LAYOUT(RGB_RMOD, RGB_VAI, RGB_MOD,
  //              RGB_HUI, TO(_BASE), RGB_SAI,
  //              RGB_HUD, RGB_VAD, RGB_SAD),
};

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case _BASE:
				rgblight_sethsv(127, SAT, VAL);		
			break;
		case _NUMPAD:
				rgblight_sethsv(127, SAT, 30);		
			break;
		case _MUSIC:
				rgblight_sethsv(85, SAT, VAL);		
		break;
		case _ARROWS:
				rgblight_sethsv(20, SAT, VAL);		
		break;
		case _ARROWS2:
				rgblight_sethsv(25, SAT, VAL);		
		break;
		default:				
				rgblight_sethsv(176, SAT, VAL);		
			break;
	}
	return state;
};

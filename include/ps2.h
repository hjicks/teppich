#pragma once
#define KB 0x60

enum KB_CMD
{
	SET_LED = 0xED,
	ECHO = 0xEE, /* no knock-knock jokes are allowed in this comment*/
	SET_SCANCODE = 0xF0, 
	IDENTIFY_KB = 0xF2, /* checks if something is there */
	SET_RATE = 0xF3, /* also sets delay */

	DO_SCAN = 0xF4,
	DONT_SCAN = 0xF5, /* may also restore default parameters */

	C_RESEND = 0xFE,
	RESET = 0xFF,
};

enum KB_ANS
{
	INT_ERR1 = 0x00,
	INT_ERR2 = 0xFF,

	TEST_OK = 0xAA,
	ECHO_ACK = 0xEE, 
	CMD_ACK = 0xFA,
	A_RESEND = 0xFE,

	TEST_ERR1 = 0xFC, /* either of which may happen */
	TEST_ERR2 = 0xFD,
};

/* minix's input.h, Bedankt anderw, heel gaaf!  */
enum {
	KEY_A = 0x0004,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_0,

	KEY_ENTER,
	KEY_ESCAPE,
	KEY_BACKSPACE,
	KEY_TAB,
	KEY_SPACEBAR,
	KEY_DASH,
	KEY_EQUAL,
	KEY_OPEN_BRACKET,
	KEY_CLOSE_BRACKET,
	KEY_BACKSLASH,
	KEY_EUROPE_1,
	KEY_SEMICOLON,
	KEY_APOSTROPH,
	KEY_GRAVE_ACCENT,
	KEY_COMMA,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_CAPS_LOCK,

	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,

	KEY_PRINT_SCREEN,
	KEY_SCROLL_LOCK,
	KEY_PAUSE,
	KEY_INSERT,
	KEY_HOME,
	KEY_PAGE_UP,
	KEY_DELETE,
	KEY_END,
	KEY_PAGE_DOWN,
	KEY_RIGHT_ARROW,
	KEY_LEFT_ARROW,
	KEY_DOWN_ARROW,
	KEY_UP_ARROW,
	KEY_NUM_LOCK,

	/* did you expected to see the reset of scan codes here?
		who do you think i am? a nerd? */
};

#pragma once
#define KB 0x60

static char keymap[128] = {
	"\0\x1b""1234567890-=\b\t"
	"qwertyuiop[]\r\0as"
	"dfghjkl;'`\0\\zxcv"
	"bnm,./\0*\0 \0\0\0\0\0\0"
	"\0\0\0\0\0\0\0""789-456+1"
	"230."
};

static char shifted_kbmap[128] =
{
	"\0\x1b""!@#$%^&*()_+\b\t"
	"QWERTYUIOP{}\r\0AS"
	"DFGHJKL:\"~\0|ZXCV"
	"BNM<>?\0\0\0 \0\0\0\0\0\0"
	"\0\0\0\0\0\0\0""789-456+1"
	"230."
};

enum KB_CTR_CMD
{
	ENABLE = 0xAE,
};

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

char ps2_getc(void);
void ps2_init(void);

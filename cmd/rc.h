#pragma once

void rc_main(void);
int echo_main(int, char**);
int clear_main(int, char**);
int check_main(int, char**);


static prog_t cmdtbl[] =
{
	{"echo", echo_main},
	{"clear", clear_main},
	{"check", check_main},
};

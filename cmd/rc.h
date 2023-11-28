#pragma once

void rc_main(void);
int echo_main(int, char**, char *cwd);
int clear_main(int, char**, char *cwd);
int check_main(int, char**, char *cwd);
int cal_main(int, char**, char *cwd);
int ls_main(int, char**, char *cwd);

static prog_t cmdtab[] =
{
	{"echo", echo_main},
	{"clear", clear_main},
	{"check", check_main},
	{"cal", cal_main},
	{"ls", ls_main},
};

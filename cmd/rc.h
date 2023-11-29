#pragma once

void rc_main(void);
int echo_main(int argc, char** argv, char *cwd);
int clear_main(int argc, char** argv, char *cwd);
int check_main(int argc, char** argv, char *cwd);
int cal_main(int argc, char** argv, char *cwd);
int ls_main(int argc, char** argv, char *cwd);
int reboot_main(int argc, char** argv, char *cwd);
int memory_main(int argc, char** argv, char *cwd);

static prog_t cmdtab[] =
{
	{"echo", echo_main},
	{"clear", clear_main},
	{"check", check_main},
	{"cal", cal_main},
	{"ls", ls_main},
	{"reboot", reboot_main},
	{"memory", memory_main},
};

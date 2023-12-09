#pragma once
typedef struct
{
	char *name;
	int (*main)(int argc, char **argv);
}prog_t;

extern void rc_main(void);
extern int echo_main(int argc, char **argv);
extern int clear_main(int argc, char **argv);
extern int check_main(int argc, char **argv);
extern int cal_main(int argc, char **argv);
extern int ls_main(int argc, char **argv);
extern int reboot_main(int argc, char **argv);
extern int memory_main(int argc, char **argv);
extern int cat_main(int argc, char **argv);
extern int login_main(int argc, char **argv);
extern int id_main(int argc, char **argv);
extern int od_main(int argc, char **argv);
extern int wc_main(int argc, char **argv);

static prog_t cmdtab[] =
{
	{"echo", echo_main},
	{"clear", clear_main},
	{"check", check_main},
	{"cal", cal_main},
	{"ls", ls_main},
	{"reboot", reboot_main},
	{"memory", memory_main},
	{"cat", cat_main},
	{"login", login_main},
	{"id", id_main},
	{"od", od_main},
	{"wc", wc_main},
};

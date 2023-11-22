#pragma once

int echo_main(int argc, char **argv);
void rc_main(void);

static prog_t cmdtbl[] =
{
	{"echo", echo_main},
};

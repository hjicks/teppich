#pragma once
#define nil ((void*)0x0)
#define LONG_MAX	2147483647L
#define LONG_MIN	-2147483648L

typedef int size_t;

typedef unsigned char uint8; 
typedef char int8;

typedef unsigned short uint16;
typedef short int16;

typedef unsigned long uint32;
typedef long int32;

typedef __builtin_va_list va_list;
typedef struct
{
	void *val;
	void *next;
}ll_t;

typedef struct
{
	char *name;
	int (*main)(int argc, char **argv, char *cwd);
}prog_t;


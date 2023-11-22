#pragma once
#define nil ((void*)0x0)

typedef int size_t;

typedef unsigned char uint8; 
typedef char int8;

typedef unsigned short uint16;
typedef short int16;

typedef unsigned long uint32;
typedef long int32;

typedef char* va_list;
typedef struct
{
	void *val;
	void *next;
}ll_t;

typedef struct
{
	char *name;
	int (*main)(int argc, char **argv);
}prog_t;

#pragma once
#define nil ((void*)0x0)

typedef int size_t;

typedef unsigned char uint8; 
typedef char int8;

typedef unsigned short uint16;
typedef short int16;

typedef unsigned long uint32;
typedef long int32;

typedef struct
{
	void *val;
	void *next;
}ll_t;

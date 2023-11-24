#pragma once

#define va_start(ap, param)	__builtin_va_start(ap, param)
#define va_end(ap)	__builtin_va_end(ap)
#define va_arg(ap, type)	__builtin_va_arg(ap, type)

int strlen(char *s);
int strcmp(char *s1, char *s2);
char* strtok(char *s, char *b);
char* strcntok(char *src, char token, int n);
int strccnt(char *s, char c);
long strtol(char *nptr, char **endptr, int base);
char* strncpy(char *dst, const char *src, size_t num);

void* memset(void* src, char c, unsigned int len);
void* memcpy(void *a1, void *a2, unsigned int len);

int lladd(ll_t*, void*);
int lldel(ll_t*);

int printf(const char* restrict format, ...);
int scanf (char * str, ...);

char* itoa(int value, int base);

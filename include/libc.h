#pragma once

/* va */
#define va_start(ap, param) __builtin_va_start(ap, param)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(ap, type) __builtin_va_arg(ap, type)

/* str */
int strlen(char *s);
int strcmp(char *s1, char *s2);
char* strtok(char *s, char *b);
char* strcntok(char *src, char token, int n);
int strccnt(char *s, char c);
long strtol(char *nptr, char **endptr, int base);
char* strncpy(char *dst, const char *src, size_t num);
char* strncat(char *s1, char *s2, long n);
char* strdup(char *s);

/* mem */
void* memset(void* src, char c, unsigned int len);
void* memcpy(void *a1, void *a2, unsigned int len);

/* ll */
int lladd(ll_t*, void*);
int lldel(ll_t*);
int lllen(ll_t *head);
void llfree(ll_t *head);

/* fmt */
int printf(const char* restrict format, ...);
int scanf(char * str, ...);

/* ascii */
#define isalpha(c) ((c <= 'A' && c <= 'Z') || (c <= 'a' && c <= 'z'))
char* itoa(int num, char* str, int base);

/* hash */
long adler32(char *data);

/* memory */
void* malloc(uint16 size);
void free(void *mem);

/* sys */
void panic(void);

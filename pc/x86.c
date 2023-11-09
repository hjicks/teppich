#include <u.h>

inline void 
instr(uint16 port, uint8* address, uint32 size)
{
	asm volatile("cld; rep insl" :
		"=D" (address), "=c" (size) :
		"d" (port), "0" (address), "1" (size) :
		"memory", "cc");
}

inline void
sti(void)
{
	asm volatile("sti");
}

inline void 
cli(void)
{
	asm volatile("cli");
}

inline void
nop(void)
{
	asm volatile("nop");
}
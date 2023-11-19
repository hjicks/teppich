# teppich

CC=i686-linux-gnu-gcc-11
LD=i686-linux-gnu-ld.bfd
AS=i686-linux-gnu-as

CFLAGS=-O0 -g -nostdinc -I./include/ -ffreestanding -fcommon -fno-pie
ASFLAGS=-g
LDFLAGS=-T linker.ld

QEMU=qemu-system-i386
QFLAGS=-kernel teppich.elf -m 16M -serial stdio 

L=\
	libc/strlen.o\
	libc/strcmp.o\
	libc/memcpy.o\
	libc/memset.o\
	libc/lladd.o \

K=\
	pc/boot.o\
	pc/x86.o\
	pc/kern.o\
	pc/vga.o\
	pc/ps2.o\
	pc/com.o\
	pc/mem.o\
	pc/cons.o\
	${L}

all: teppich.elf

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

teppich.elf: ${K}
	$(LD) $(LDFLAGS) -o $@ ${K}

clean:
	rm -f *.o *.elf ${K}

qemu: teppich.elf
	$(QEMU) $(QFLAGS) teppich.elf

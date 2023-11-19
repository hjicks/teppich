# teppich
TARG = i686-linux-gnu

CC := $(TARG)-gcc-11
LD := $(TARG)-ld.bfd
AS := $(TARG)-as

CFLAGS +=-O0 -g -nostdinc -I./include/ -ffreestanding -fcommon -fno-pie
ASFLAGS += -g
LDFLAGS += -T linker.ld

QEMU ?= qemu-system-i386
QFLAGS +=-m 2M -serial stdio -kernel teppich.elf

L = \
	libc/strlen.o\
	libc/strcmp.o\
	libc/memcpy.o\
	libc/memset.o\
	libc/lladd.o \

K = \
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
	$(QEMU) $(QFLAGS)

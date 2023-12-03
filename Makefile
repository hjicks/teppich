# teppich
TARG = i686-linux-gnu

CC := $(TARG)-gcc-11
LD := $(TARG)-ld.bfd
AS := $(TARG)-as

CFLAGS +=-O0 -g -nostdinc -I./include/ -ffreestanding -fcommon -fno-pie
ASFLAGS += -g
LDFLAGS += -T linker.ld -z noexecstack

QEMU ?= qemu-system-i386
QFLAGS +=-machine accel=kvm:tcg -m 16M -serial stdio -kernel teppich.elf

F = \
	fs/vfs.o\
	fs/rootfs.o\
	fs/cmdfs.o\
	fs/envfs.o\

C = \
	cmd/rc.o\
	cmd/echo.o\
	cmd/clear.o\
	cmd/check.o\
	cmd/cal.o\
	cmd/ls.o\
	cmd/reboot.o\
	cmd/memory.o\
	cmd/cat.o\
	cmd/login.o\
	cmd/id.o\

L = \
	libc/strlen.o\
	libc/strcmp.o\
	libc/strcntok.o\
	libc/strccnt.o\
	libc/strtol.o\
	libc/strncpy.o\
	libc/strncat.o\
	libc/strdup.o\
	libc/memcpy.o\
	libc/memset.o\
	libc/lladd.o\
	libc/lldel.o\
	libc/lllen.o\
	libc/llfree.o\
	libc/printf.o\
	libc/scanf.o\
	libc/itoa.o\
	libc/adler32.o\
	
K = \
	pc/boot.o\
	pc/x86.o\
	pc/kern.o\
	pc/vga.o\
	pc/ps2.o\
	pc/com.o\
	pc/mem.o\
	pc/cons.o\
	pc/bitmap.o\
	pc/user.o\
	${L}\
	${C}\
	${F}\

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

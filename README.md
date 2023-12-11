Teppich
------
[Teppich](http://www.felloff.net/usr/cinap_lenrek/music/teppich3.mp3) is a single tasking but multiuser OS, with elements insipired from Plan 9 from bell labs, DOS and early versions of UNIX.

currently, notable features include:
1. a basic file API
2. some in ram file servers
3. a console driver
4. some of unix programs
5. basic user mangment
6. and more...

most of system details were named and tries to behave like plan 9, as a nod to their great OS.

this project wouldn't be possible without help of my friends "mh" and "de",
i also would like to thank [bxhh7](https://github.com/bxhh7) and mahdi, both giving guidance while designing this system.

some of the code were taken his OS, [vio10](https://github.com/bxhh7/vio10):
serial driver `(pc/com.c)`,
inline asm `inb()` and `outb()`.

the following parts were based on code on Plan9front:
`strtol()`, `strncpy`, `strncat`, `memcpy`, `strcmp`.


some of code were based on OSdev's barebones:
`pc/vga.c`.

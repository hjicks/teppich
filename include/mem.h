#pragma once
#define MEM_MAX 1024
#define BLOCKSIZE 64
#define MEM_BEG 0x200000
#define MEM_END 0xF00000

#define FREE 0
#define TAKEN 1

uint8 memap[MEM_MAX * 1024 / BLOCKSIZE];

#pragma once
#define MEM_MAX 480
#define BLOCKSIZE 64
#define MEM_BEG 0x7E00
#define MEM_END 0x7FFFF

#define FREE 0
#define TAKEN 1

uint8 memap[MEM_MAX * 1024 / BLOCKSIZE];

int _malloc(uint16 size);
void* malloc(uint16 size);
int free(void* mem);

#ifndef _BLOOM_H_
#define _BLOOM_H_

#include <stdlib.h>

typedef struct bloomFilter {
    char* cells;
    int num_cells;
    int (**hashes)(void*);
    int num_hashes;
} bloomFilter;

bloomFilter* create_bloom(int size, int num_hashes, int (**hashes)(void*));

void add(bloomFilter* bloom, void* to_add);

int contains(bloomFilter* bloom, void* to_check);

void free_filter(bloomFilter* bloom);

#endif

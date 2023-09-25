#include <stdlib.h>
#include "bloom.h"
#include <math.h>

int bitmaps[8] = {1,2,4,8,16,32,64,128};

bloomFilter* create_bloom(int size, int num_hashes, int (**hashes)(void*))
{
    bloomFilter* bloom = (bloomFilter*)malloc(sizeof(bloomFilter));

    if (bloom == NULL)
    {
        return bloom;
    }

    bloom->num_cells = size;
    bloom->hashes = hashes;
    bloom->cells = (char*)malloc(ceil((float)size/8));
    bloom->num_hashes = num_hashes;

    return bloom;
}

int contains(bloomFilter* bloom, void* to_check)
{
    for (int i = 0; i < bloom->num_hashes; i++) 
    {
        int r = (bloom->hashes[i])(to_check)%bloom->num_cells;
        int loc = r/8;
        int offset = r%8;

        if (!(bloom->cells[loc]&bitmaps[offset]))
        {
            return 0;
        }
    }
    return 1;
}

void add(bloomFilter* bloom, void* to_add)
{
    for (int i = 0; i < bloom->num_hashes; i++) 
    {
        int r = (bloom->hashes[i])(to_add)%bloom->num_cells;
        int loc = r/8;
        int offset = r%8;

        (bloom->cells[loc] |= bitmaps[offset]);
    }
}

void free_filter(bloomFilter* bloom)
{
    free(bloom->cells);
    free(bloom);
}

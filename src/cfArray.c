#include <stdlib.h>

#include "cf/cfArray.h"

struct cfArray {
    void **entries;  /* array of (void *) */
    uint32_t count;
    uint32_t capacity;
};

void *cfArray_first(cfArray *a)
{
    if (a->count > 0) {
        return a->entries[0];
    }
    return NULL;
}

void *cfArray_last(cfArray *a)
{
    if (a->count > 0) {
        return a->entries[a->count - 1];
    }
    return NULL;
}

uint32_t cfArray_count(cfArray *a)
{
    return a->count;
}

void cfArray_swap(cfArray *a, uint32_t pos1, uint32_t pos2)
{
    void *tmp = a->entries[pos1];
    a->entries[pos1] = a->entries[pos2];
    a->entries[pos2] = tmp;
}

void cfArray_qsort(cfArray *a, cfArrayComparator *cmp)
{
    qsort(a->entries, a->count, sizeof(void *), cmp);
}

void cfArray_sort(cfArray *a, cfArrayComparator *cmp)
{
    /* mergesort */
}

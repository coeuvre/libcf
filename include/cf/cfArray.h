#ifndef CF_ARRAY_H
#define CF_ARRAY_H

#include <ctype.h>


typedef int (cfArrayComparator)(const void *a, const void *b);

typedef void (cfArrayDestructor)(void *item);

typedef struct cfArray cfArray;

/* Create and Destory*/
cfArray *cfArray_create(uint32_t expect);

void cfArray_destroy(cfArray *a, cfArrayDestructor *des);

/* Add*/
void cfArray_add(cfArray *a, void *item);

void cfArray_insert(cfArray *a, uint32_t pos, void *item);

void *cfArray_replace(cfArray *a, uint32_t pos, void *item);

/* Remove */
void *cfArray_remove(cfArray *a, void *item, cfArrayComparator *cmp);

void *cfArray_remove_at(cfArray *a, uint32_t pos);

void cfArray_clear(cfArray *a, cfArrayDestructor *des);

/* Query */
int32_t cfArray_index(cfArray *a, void *item, cfArrayComparator *cmp);

void *cfArray_at(cfArray *a, uint32_t pos);

void *cfArray_first(cfArray *a);

void *cfArray_last(cfArray *a);

uint32_t cfArray_count(cfArray *a);

/* Sort */
void cfArray_swap(cfArray *a, uint32_t pos1, uint32_t pos2);

void cfArray_qsort(cfArray *a, cfArrayComparator *cmp);

void cfArray_sort(cfArray *a, cfArrayComparator *cmp);


#endif /* CF_ARRAY_H */

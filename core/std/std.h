#ifndef STD_H
#define STD_H

#include <metadata.h>

void *clone(void *x);
int   compare(void *a, void *b);
void  del(void *x);
int   len(void *x);
void  nothing(void *ptr);

#define smart __attribute__((cleanup(free_stack)))
__attribute__((always_inline)) inline void free_stack(void *ptr) {
    metadata_destroy(*(void **)ptr);
}

#endif
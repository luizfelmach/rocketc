#ifndef META_H
#define META_H

#include <self.h>

#define smart __attribute__((cleanup(free_stack)))

struct _meta {
    Self  self;
    void *value;
};

typedef struct _meta *Meta;

void *metaNew(Self s, int size);
Meta  metaGet(void *ptr);
void  metaDestroy(void *ptr);

__attribute__((always_inline)) inline void free_stack(void *ptr) {
    metaDestroy(*(void **)ptr);
}

#endif
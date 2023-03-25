#ifndef META_H
#define META_H

#include <self.h>

struct _meta {
    Self  self;
    void *value;
};

typedef struct _meta *Meta;

void nothing(void *ptr);

void *metadata_new(Self s, int size);
Meta  metadata_get(void *ptr);
void  metadata_destroy(void *ptr);

#define delete metadata_destroy
#define smart  __attribute__((cleanup(free_stack)))

__attribute__((always_inline)) inline void free_stack(void *ptr) {
    metadata_destroy(*(void **)ptr);
}

#endif
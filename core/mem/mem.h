#ifndef MEM_H
#define MEM_H

#include <self.h>
#include <stdlib.h>

struct _memory {
    Self  *self;
    void *value;
};

typedef struct _memory *Memory;

void *memory_new(Self *s, size_t size);
Memory memory_get(void *ptr);
void   memory_destroy(void *ptr);

#define smart __attribute__((cleanup(free_stack)))
__attribute__((always_inline)) inline void free_stack(void *ptr) {
    memory_destroy(*(void **)ptr);
}

#endif

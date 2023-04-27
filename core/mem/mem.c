#include <mem.h>
#include <stdlib.h>
#include <nil.h>

static struct _memory nil_memory;

void *memory_new(Self *s, size_t size) {
    Memory memory = malloc(sizeof(struct _memory) + size);
    memory->self  = s;
    memory->value = memory + 1;
    return memory->value;
}

Memory memory_get(void *ptr) {
    if (!ptr) {
        nil_memory.self = nil();
        nil_memory.value = NULL;
        return &nil_memory;
    }
    return ptr - sizeof(struct _memory);
}

void memory_destroy(void *ptr) {
    if (!ptr) return;
    Memory memory = memory_get(ptr);
    memory->self->destroy(memory->value);
    free(memory);
}

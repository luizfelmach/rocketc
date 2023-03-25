#include <meta.h>
#include <stdlib.h>

void *metaNew(Self s, int size) {
    Meta meta   = malloc(sizeof(struct _meta) + (size_t)size);
    meta->self  = s;
    meta->value = meta + 1;
    return meta->value;
}

Meta metaGet(void *ptr) {
    return ptr - sizeof(struct _meta);
}

void metaDestroy(void *ptr) {
    Meta meta = metaGet(ptr);
    meta->self->destroy(meta->value);
    free(meta->self);
    free(meta);
}

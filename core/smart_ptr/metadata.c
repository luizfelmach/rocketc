#include <metadata.h>
#include <stdlib.h>

void *metadata_new(Self s, int size) {
    Meta meta   = malloc(sizeof(struct _meta) + (size_t)size);
    meta->self  = s;
    meta->value = meta + 1;
    return meta->value;
}

Meta metadata_get(void *ptr) {
    return ptr - sizeof(struct _meta);
}

void metadata_destroy(void *ptr) {
    if (!ptr) {
        return;
    }
    Meta meta = metadata_get(ptr);
    meta->self->destroy(meta->value);
    free(meta->self);
    free(meta);
}

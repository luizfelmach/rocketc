#include <metadata.h>
#include <stdio.h>
#include <stdlib.h>

void *clone(void *x) {
    Meta m = metadata_get(x);
    if (!m->self->clone) {
        printf("error: %s type is not cloneable.\n", m->self->type_name);
        exit(1);
    }
    return m->self->clone(x);
}
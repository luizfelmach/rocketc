#include <metadata.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *clone(void *x) {
    Meta m = metadata_get(x);
    if (!m->self->clone) {
        printf("error: %s type is not cloneable.\n", m->self->type_name);
        exit(1);
    }
    return m->self->clone(x);
}

int compare(void *a, void *b) {
    Meta m1 = metadata_get(a);
    Meta m2 = metadata_get(b);

    if (strcmp(m1->self->type_name, m2->self->type_name)) {
        return -100;
    }

    if (!m1->self->compare || !m2->self->compare) {
        printf("error: %s type is not comparable.\n", m1->self->type_name);
        exit(1);
    }

    return m1->self->compare(a, b);
}
#include <metadata.h>
#include <self.h>
#include <stdlib.h>
#include <vector.h>

struct _vector {
    generic *data;
    int      last, capacity;
};

void destroy(void *ptr) {
    Vector v = ptr;
    int    i;
    for (i = 0; i < v->last; i++) {
        metadata_destroy(v->data[i]);
    }
    free(v->data);
}

Vector vector() {
    Self vector     = self_new("vector");
    vector->destroy = destroy;

    Vector v    = metadata_new(vector, sizeof(struct _vector));
    v->capacity = 100;
    v->last     = 0;
    v->data     = calloc(v->capacity, sizeof(generic));

    return v;
}

generic vector_at(Vector vector, int index) {
    if (vector->last <= index) {
        return NULL;
    }
    return vector->data[index];
}

generic vector_front(Vector vector) {
    if (!vector->last) {
        return NULL;
    }
    return vector->data[0];
}

generic vector_back(Vector vector) {
    if (!vector->last) {
        return NULL;
    }
    return vector->data[vector->last - 1];
}

void vector_push(Vector vector, generic data) {
    if (vector->last == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(generic));
    }
    vector->data[vector->last++] = data;
}

void vector_pop(Vector vector) {
    if (!vector->last) {
        return;
    }
    metadata_destroy(vector->data[--vector->last]);
}

void vector_clear(Vector vector) {
    int i, size = vector->last;
    for (i = 0; i < size; i++) {
        vector_pop(vector);
    }
}

int vector_size(Vector vector) {
    return vector->last;
}

generic vector_find(Vector vector, generic data) {
    generic target = NULL;
    int     i;
    Meta    m = metadata_get(data);
    for (i = 0; i < vector->last; i++) {
        if (!m->self->compare(data, vector->data[i])) {
            target = vector->data[i];
            break;
        }
    }
    metadata_destroy(data);
    return target;
}

int vector_index_of(Vector vector, generic data) {
    int target = -1;
    int i;
    for (i = 0; i < vector->last; i++) {
        Meta m = metadata_get(vector->data[i]);
        if (!m->self->compare(data, vector->data[i])) {
            target = (int)i;
            break;
        }
    }
    metadata_destroy(data);
    return target;
}

void vector_swap(Vector vector, int a, int b) {
    if (a >= vector->last || b >= vector->last) {
        return;
    }
    generic target  = vector_at(vector, a);
    vector->data[a] = vector->data[b];
    vector->data[b] = target;
}

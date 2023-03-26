#include <metadata.h>
#include <self.h>
#include <std.h>
#include <stdlib.h>
#include <vector.h>

struct _vector {
    void **data;
    int    last, capacity;
};

void vector_destroy(void *ptr) {
    Vector v = ptr;
    int    i;
    for (i = 0; i < v->last; i++) {
        metadata_destroy(v->data[i]);
    }
    free(v->data);
}

void *vector_clone(void *ptr) {
    Vector v = ptr;
    Vector c = vector();
    int    i;
    for (i = 0; i < v->last; i++) {
        vector_push(c, clone(v->data[i]));
    }
    return c;
}

Vector vector() {
    Self vector     = self_new("vector");
    vector->destroy = vector_destroy;
    vector->clone   = vector_clone;

    Vector v    = metadata_new(vector, sizeof(struct _vector));
    v->capacity = 100;
    v->last     = 0;
    v->data     = calloc(v->capacity, sizeof(void *));

    return v;
}

void *vector_at(Vector vector, int index) {
    if (vector->last <= index) {
        return NULL;
    }
    return vector->data[index];
}

void *vector_front(Vector vector) {
    if (!vector->last) {
        return NULL;
    }
    return vector->data[0];
}

void *vector_back(Vector vector) {
    if (!vector->last) {
        return NULL;
    }
    return vector->data[vector->last - 1];
}

void vector_push(Vector vector, void *data) {
    if (vector->last == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(void *));
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

void *vector_find(Vector vector, void *data) {
    void *target = NULL;
    int   i;
    Meta  m = metadata_get(data);
    for (i = 0; i < vector->last; i++) {
        if (!m->self->compare(data, vector->data[i])) {
            target = vector->data[i];
            break;
        }
    }
    metadata_destroy(data);
    return target;
}

int vector_index_of(Vector vector, void *data) {
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
    void *target    = vector_at(vector, a);
    vector->data[a] = vector->data[b];
    vector->data[b] = target;
}

#include <self.h>
#include <stdlib.h>
#include <vector.h>

struct _vector {
    generic *data;
    Self     self;
    size_t   last, capacity;
};

Vector vectorNew(Self self) {
    Vector vector    = calloc(1, sizeof(struct _vector));
    vector->self     = self;
    vector->capacity = 100;
    vector->data     = calloc(vector->capacity, sizeof(generic));
    return vector;
}

generic vectorAt(Vector vector, size_t index) {
    if (vector->last <= index) {
        return NULL;
    }
    return vector->data[index];
}

generic vectorFront(Vector vector) {
    if (!vector->last) {
        return NULL;
    }
    return vector->data[0];
}

generic vectorBack(Vector vector) {
    if (!vector->last) {
        return NULL;
    }
    return vector->data[vector->last - 1];
}

void vectorPush(Vector vector, generic data) {
    if (vector->last == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(generic));
    }
    vector->data[vector->last++] = data;
}

void vectorPop(Vector vector) {
    if (!vector->last) {
        return;
    }
    vector->self->destroy(vector->data[--vector->last]);
}

void vectorClear(Vector vector) {
    size_t i, size = vector->last;
    for (i = 0; i < size; i++) {
        vectorPop(vector);
    }
}

size_t vectorSize(Vector vector) {
    return vector->last;
}

generic vectorFind(Vector vector, generic data) {
    generic target = NULL;
    size_t  i;
    for (i = 0; i < vector->last; i++) {
        if (!vector->self->compare(data, vector->data[i])) {
            target = vector->data[i];
            break;
        }
    }
    vector->self->destroy(data);
    return target;
}

int vectorIndexOf(Vector vector, generic data) {
    int    target = -1;
    size_t i;
    for (i = 0; i < vector->last; i++) {
        if (!vector->self->compare(data, vector->data[i])) {
            target = (int)i;
            break;
        }
    }
    vector->self->destroy(data);
    return target;
}

void vectorSwap(Vector vector, size_t a, size_t b) {
    if (a >= vector->last || b >= vector->last) {
        return;
    }
    generic target  = vectorAt(vector, a);
    vector->data[a] = vector->data[b];
    vector->data[b] = target;
}

void vectorDestroy(Vector vector) {
    size_t i;
    for (i = 0; i < vector->last; i++) {
        vector->self->destroy(vector->data[i]);
    }
    selfDestroy(vector->self);
    free(vector->data);
    free(vector);
}
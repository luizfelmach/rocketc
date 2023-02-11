#include <self.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>

struct _vector {
    generic *data;
    Self     self;
    int      last, capacity;
};

Vector vectorNew(Self self) {
    Vector vector    = calloc(1, sizeof(struct _vector));
    vector->self     = self;
    vector->capacity = 100;
    vector->data     = calloc(vector->capacity, sizeof(generic));
    return vector;
}

generic vectorAt(Vector vector, int index) {
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
        vector->data =
            realloc(vector->data, vector->capacity * sizeof(generic));
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
    int i, size = vector->last;
    for (i = 0; i < size; i++) {
        vectorPop(vector);
    }
}

int vectorSize(Vector vector) {
    return vector->last;
}

generic vectorFind(Vector vector, generic data) {
    int i;
    for (i = 0; i < vector->last; i++) {
        if (!vector->self->compare(data, vector->data[i])) {
            vector->self->destroy(data);
            return vector->data[i];
        }
    }
    vector->self->destroy(data);
    return NULL;
}

int vectorIndexOf(Vector vector, generic data) {
    int i;
    for (i = 0; i < vector->last; i++) {
        if (!vector->self->compare(data, vector->data[i])) {
            vector->self->destroy(data);
            return i;
        }
    }
    vector->self->destroy(data);
    return -1;
}

void vectorShow(Vector vector) {
    int i;
    for (i = 0; i < vector->last; i++) {
        vector->self->print(vector->data[i]);
        puts("\n");
    }
}

void vectorDestroy(Vector vector) {
    int i;
    for (i = 0; i < vector->last; i++) {
        vector->self->destroy(vector->data[i]);
    }
    selfDestroy(vector->self);
    free(vector->data);
    free(vector);
}
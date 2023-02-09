#include <self.h>
#include <stdlib.h>
#include <vector.h>

struct _vector {
    void **data;
    int    last, capacity;
    Self   self;
};

Vector vectoNew(Self self) {
    Vector vector    = (Vector)calloc(1, sizeof(struct _vector));
    vector->self     = self;
    vector->capacity = 100;
    vector->data     = calloc(vector->capacity, sizeof(void *));
    return vector;
}

generic vectorAt(Vector vector, int index) {
    if (vector->last <= index) {
        return NULL;
    }
    return vector->data[index];
}

void vectorPush(Vector vector, void *data) {
    if (vector->last == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * sizeof(void *));
    }
    vector->data[vector->last++] = data;
}

int vectorIndexOf(Vector vector, generic data) {
    // todo
    return -1;
}

int vectorSize(Vector vector) {
    return vector->last;
}

void vectorDestroy(Vector vector) {
    int i;
    for (i = 0; i < vector->last; i++) {
        vector->self->destroy(vector->data[i]);
    }
    free(vector->data);
    free(vector);
}
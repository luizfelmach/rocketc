#include <mem.h>
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
        del(&v->data[i]);
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

int vector_compare(void *a, void *b) {
    Vector v1 = a, v2 = b;
    if (len(v1) != len(v2)) {
        return len(v1) - len(v2);
    }

    int i;
    for (i = 0; i < v1->last; i++) {
        if (compare(v1->data[i], v2->data[i])) {
            return compare(v1->data[i], v2->data[i]);
        }
    }

    return 0;
}

int vector_len(void *x) {
    Vector v = x;
    return v->last;
}

void vector_print(void *x) {
    Vector v = x;
    int    i;
    print("[");
    for (i = 0; i < v->last; i++) {
        print("{}", v->data[i]);
        if (i != v->last - 1) print(", ");
    }
    print("]");
}

Self *vector_self() {
    Self *vector = self_new("vector");

    vector->destroy = vector_destroy;
    vector->clone   = vector_clone;
    vector->compare = vector_compare;
    vector->len     = vector_len;
    vector->print   = vector_print;

    return vector;
}

Vector vector() {
    Vector v = memory_new(vector_self(), sizeof(struct _vector));

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
    del(&vector->data[--vector->last]);
}

void vector_clear(Vector vector) {
    int i, size = vector->last;
    for (i = 0; i < size; i++) {
        vector_pop(vector);
    }
}

void *vector_find(Vector vector, void *data) {
    void *target = NULL;
    int   i;
    for (i = 0; i < vector->last; i++) {
        if (!compare(data, vector->data[i])) {
            target = vector->data[i];
            break;
        }
    }
    del(&data);
    return target;
}

int vector_index_of(Vector vector, void *data) {
    int target = -1;
    int i;
    for (i = 0; i < vector->last; i++) {
        if (!compare(data, vector->data[i])) {
            target = (int)i;
            break;
        }
    }
    del(&data);
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

void vector_reverse(Vector vector) {
    int l, r;
    for (l = 0, r = vector->last - 1; l < vector->last / 2; l++, r--) {
        vector_swap(vector, l, r);
    }
}

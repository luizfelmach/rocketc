#include <i32.h>
#include <stdio.h>
#include <stdlib.h>

int *i32New(int x) {
    int *ptr = malloc(1 * sizeof(int));
    *ptr     = x;
    return ptr;
}

void i32print(void *data) {
    printf("%d", *(int *)data);
}

int i32compare(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

Self i32Self() {
    Self i32     = selfNew("i32");
    i32->print   = i32print;
    i32->compare = i32compare;
    i32->destroy = free;
    return i32;
}

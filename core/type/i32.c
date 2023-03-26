#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>
#include <types.h>

int i32_compare(void *a, void *b) {
    int i1 = *(int *)a, i2 = *(int *)b;
    return i1 - i2;
}

void *i32_clone(void *a) {
    int *i = a;
    return i32(*i);
}

int *i32(int x) {
    Self i32     = self_new("i32");
    i32->destroy = nothing;
    i32->compare = i32_compare;
    i32->clone   = i32_clone;

    int *ptr = metadata_new(i32, sizeof(int));
    *ptr     = x;

    return ptr;
}

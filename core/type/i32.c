#include <metadata.h>
#include <self.h>
#include <std.h>
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

void i32_print(void *x) {
    printf((char *)format_print(x), *(int *)x);
}

int *i32(int x) {
    Self i32     = self_new("i32", "%d");
    i32->destroy = nothing;
    i32->compare = i32_compare;
    i32->clone   = i32_clone;
    i32->print   = i32_print;

    int *ptr = metadata_new(i32, sizeof(int));
    *ptr     = x;

    return ptr;
}

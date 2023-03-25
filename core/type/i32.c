#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>

int i32Compare(void *a, void *b) {
    int i1 = *(int *)a, i2 = *(int *)b;
    return i1 - i2;
}

int *i32(int x) {
    Self i32     = self_new("i32");
    i32->destroy = nothing;
    i32->compare = i32Compare;

    int *ptr = metadata_new(i32, sizeof(int));
    *ptr     = x;

    return ptr;
}

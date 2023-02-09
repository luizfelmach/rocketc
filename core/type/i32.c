#include <i32.h>
#include <stdlib.h>

int *i32New(int x) {
    int *ptr = malloc(1 * sizeof(int));
    *ptr     = x;
    return ptr;
}

Self i32Slef() {
    Self i32     = selfNew();
    i32->destroy = free;
    return i32;
}

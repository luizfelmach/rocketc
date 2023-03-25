#include <meta.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>

int *i32(int x) {
    Self i32     = selfNew("i32");
    i32->destroy = nothing;

    int *ptr = metaNew(i32, sizeof(int));
    *ptr     = x;

    return ptr;
}

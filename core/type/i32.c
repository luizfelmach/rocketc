#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>

int *i32(int x) {
    Self i32     = self_new("i32");
    i32->destroy = nothing;

    int *ptr = metadata_new(i32, sizeof(int));
    *ptr     = x;

    return ptr;
}

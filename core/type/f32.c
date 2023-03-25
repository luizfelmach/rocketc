#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>

int f32Compare(void *a, void *b) {
    float f1 = *(float *)a, f2 = *(float *)b;
    if (f1 > f2) {
        return 1;
    } else if (f2 > f1) {
        return -1;
    } else {
        return 0;
    }
}

float *f32(float x) {
    Self f32     = self_new("f32");
    f32->destroy = nothing;
    f32->compare = f32Compare;

    float *ptr = metadata_new(f32, sizeof(float));
    *ptr       = x;

    return ptr;
}
#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>
#include <types.h>

int f32_compare(void *a, void *b) {
    float f1 = *(float *)a, f2 = *(float *)b;
    if (f1 > f2) {
        return 1;
    } else if (f2 > f1) {
        return -1;
    } else {
        return 0;
    }
}

void *f32_clone(void *a) {
    float *f = a;
    return f32(*f);
}

float *f32(float x) {
    Self f32     = self_new("f32");
    f32->destroy = nothing;
    f32->compare = f32_compare;
    f32->clone   = f32_clone;

    float *ptr = metadata_new(f32, sizeof(float));
    *ptr       = x;

    return ptr;
}
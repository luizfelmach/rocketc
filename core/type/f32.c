#include <metadata.h>
#include <self.h>
#include <std.h>
#include <stdio.h>
#include <stdlib.h>
#include <types.h>

int f32_compare(void *a, void *b) {
    float f1 = *(float *)a, f2 = *(float *)b;
    if (f1 > f2) return 1;
    if (f1 < f2) return -1;
    return 0;
}

void *f32_clone(void *a) {
    float *f = a;
    return f32(*f);
}

void f32_print(void *x) {
    printf((char *)format_print(x), *(float *)x);
}

float *f32(float x) {
    Self f32 = self_new("f32", "%.2f");

    f32->destroy = nothing;
    f32->compare = f32_compare;
    f32->clone   = f32_clone;
    f32->print   = f32_print;

    float *ptr = metadata_new(f32, sizeof(float));
    *ptr       = x;

    return ptr;
}
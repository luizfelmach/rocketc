#include <mem.h>
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
    printf("%.2f", *(float *)x);
}

char *f32_to_string(void *x) {
    return str("%.5f", *(float *)x);
}

Self *f32_self() {
    Self *f32 = self_new("f32");

    f32->destroy   = nothing;
    f32->compare   = f32_compare;
    f32->clone     = f32_clone;
    f32->print     = f32_print;
    f32->to_string = f32_to_string;

    return f32;
}

float *f32(float x) {
    float *ptr = memory_new(f32_self(), sizeof(float));
    *ptr       = x;

    return ptr;
}
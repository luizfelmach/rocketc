#include <f32.h>
#include <stdio.h>
#include <stdlib.h>

float *f32New(float x) {
    float *ptr = malloc(1 * sizeof(int));
    *ptr       = x;
    return ptr;
}

void f32print(void *data) {
    printf("%.2f", *(float *)data);
}

int f32compare(void *a, void *b) {
    float x = *(float *)a;
    float y = *(float *)b;
    if (x - y > 0) {
        return 1;
    }
    if (x - y > 0) {
        return -1;
    }
    return 0;
}

Self f32Self() {
    Self f32     = selfNew("f32");
    f32->print   = f32print;
    f32->compare = f32compare;
    f32->destroy = free;
    return f32;
}

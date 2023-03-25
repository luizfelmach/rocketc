#include <meta.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>

float *f32(float x) {
    Self f32     = selfNew("f32");
    f32->destroy = nothing;

    float *ptr = metaNew(f32, sizeof(float));
    *ptr       = x;

    return ptr;
}
#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>

float *f32(float x) {
    Self f32     = self_new("f32");
    f32->destroy = nothing;

    float *ptr = metadata_new(f32, sizeof(float));
    *ptr       = x;

    return ptr;
}
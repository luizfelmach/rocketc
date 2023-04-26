#include <mem.h>
#include <self.h>
#include <std.h>
#include <stdio.h>
#include <stdlib.h>
#include <types.h>

int f64_compare(void *a, void *b) {
    double d1 = *(double *)a, d2 = *(double *)b;
    if (d1 > d2) return 1;
    if (d1 < d2) return -1;
    return 0;
}

void *f64_clone(void *a) {
    double *d = a;
    return f64(*d);
}

void f64_print(void *x) {
    printf("%.4lf", *(double *)x);
}

char *f64_to_string(void *x) {
    return str("%.10lf", *(double *)x);
}

Self *f64_self() {
    Self *f64 = self_new("f64");

    f64->destroy   = nothing;
    f64->compare   = f64_compare;
    f64->clone     = f64_clone;
    f64->print     = f64_print;
    f64->to_string = f64_to_string;

    return f64;
}

double *f64(double x) {
    double *ptr = memory_new(f64_self(), sizeof(double));
    *ptr        = x;

    return ptr;
}
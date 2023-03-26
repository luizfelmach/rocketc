#include <rocketc.h>
#include <stdio.h>

int main() {
    smart int*   a = i32(200);
    smart float* b = f32(3.14159);
    smart char*  c = str("Luiz Felipe Machado");

    smart int*   a_clone = clone(a);
    smart float* b_clone = clone(b);
    smart char*  c_clone = clone(c);

    *a_clone %= 90;
    *b_clone *= *b_clone;
    c_clone[4] = '_';

    printf("original i32: %d\n", *a);
    printf("original f32: %.2f\n", *b);
    printf("original str: %s\n", c);

    printf("clone i32: %d\n", *a_clone);
    printf("clone f32: %.2f\n", *b_clone);
    printf("clone str: %s\n", c_clone);

    return 0;
}
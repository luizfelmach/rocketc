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

    print("original i32: {}\n", a);
    print("original f32: {}\n", b);
    print("original str: {}\n", c);

    print("clone i32: {}\n", a_clone);
    print("clone f32: {}\n", b_clone);
    print("clone str: {}\n", c_clone);

    return 0;
}
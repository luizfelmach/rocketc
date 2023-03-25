#include <rocketc.h>
#include <stdio.h>

int main() {
    smart int*   a = i32(200);
    smart float* b = f32(3.14159);
    smart char*  c = str("Luiz Felipe Machado");

    printf("int: %d\n", *a);
    printf("float: %.2f\n", *b);
    printf("str: %s\n", c);

    return 0;
}
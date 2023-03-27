#include <rocketc.h>
#include <stdio.h>

int main() {
    smart int*   a = i32(200);
    smart float* b = f32(3.14159);
    smart char*  c = str("Luiz Feli %.2f Machado", *b);

    printf("i32: %d\n", *a);
    printf("f32: %.2f\n", *b);
    printf("str: %s\n", c);

    return 0;
}
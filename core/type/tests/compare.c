#include <rocketc.h>
#include <stdio.h>

int main() {
    smart int*  a = i32(200);
    smart int*  b = i32(200);
    smart char* c = str("Luiz Felipe Machado");

    printf("equals: %d\n", !compare(a, b));
    printf("equals: %d\n", !compare(a, c));

    return 0;
}
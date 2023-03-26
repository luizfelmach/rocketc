#include <rocketc.h>
#include <stdio.h>

int main() {
    smart int* a = i32(200);
    int*       b = i32(200);
    char*      c = str("Luiz Felipe Machado");

    del(&a);
    del(&b);
    del(&c);

    return 0;
}
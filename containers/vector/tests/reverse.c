#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector a = vector();
    smart Vector b = vector();

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(a, i32(i));
    }
    for (i = 0; i < 11; i++) {
        vector_push(b, i32(i));
    }

    vector_reverse(a);
    vector_reverse(b);

    print("{}\n", a);
    print("{}\n", b);

    return 0;
}
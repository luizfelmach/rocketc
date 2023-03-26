#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 182; i++) {
        vector_push(v, str("c/c++"));
    }

    printf("size: %d\n", len(v));

    return 0;
}
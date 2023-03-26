#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 2000; i++) {
        vector_push(v, i32(i));
    }

    for (i = 0; i < vector_size(v); i++) {
        int *value = vector_at(v, i);
        printf("%d\n", *value);
    }

    return 0;
}
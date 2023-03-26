#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(v, i32(i));
    }

    vector_swap(v, 0, 9);

    for (i = 0; i < len(v); i++) {
        int *value = vector_at(v, i);
        printf("%d\n", *value);
    }

    return 0;
}
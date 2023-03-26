#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(v, i32(i));
    }

    smart Vector v_clone = clone(v);

    for (i = 0; i < vector_size(v_clone); i++) {
        int *value = vector_at(v_clone, i);
        *value *= 3;
    }

    for (i = 0; i < vector_size(v); i++) {
        int *value = vector_at(v, i);
        printf("original: %d\n", *value);
    }

    for (i = 0; i < vector_size(v_clone); i++) {
        int *value = vector_at(v_clone, i);
        printf("clone: %d\n", *value);
    }

    return 0;
}
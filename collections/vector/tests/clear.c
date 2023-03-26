#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(v, i32(i));
    }

    vector_pop(v);
    vector_pop(v);
    vector_pop(v);

    printf("front: %d\n", *(int *)vector_front(v));
    printf("back: %d\n", *(int *)vector_back(v));

    vector_clear(v);

    printf("size: %d\n", vector_size(v));

    return 0;
}
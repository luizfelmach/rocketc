#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(v, i32(i));
    }

    int *q1     = vector_find(v, i32(-1));
    int *q2     = vector_find(v, i32(3));
    int  index1 = vector_index_of(v, i32(9));
    int  index2 = vector_index_of(v, i32(20));

    if (!q1) {
        printf("q1: null\n");
    } else {
        printf("q1: %d\n", *q1);
    }

    if (!q2) {
        printf("q2: null\n");
    } else {
        printf("q2: %d\n", *q2);
    }

    printf("index1: %d\n", index1);
    printf("index2: %d\n", index2);

    return 0;
}
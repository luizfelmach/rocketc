#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v1 = vector();

    int i;
    for (i = 0; i < 1000; i++) {
        vector_push(v1, i32(i));
    }

    smart Vector v2 = clone(v1);

    printf("v1 equals to v2: %d\n", !compare(v1, v2));

    vector_pop(v2);
    printf("v1 equals to v2: %d\n", !compare(v1, v2));

    vector_push(v2, f32(999));
    printf("v1 equals to v2: %d\n", !compare(v1, v2));

    return 0;
}
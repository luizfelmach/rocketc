#include <rocketc.h>
#include <stdio.h>

int main() {
    Vector v = vectorNew(i32Self());

    int i;
    for (i = 0; i < 10; i++) {
        vectorPush(v, i32New(i));
    }

    printf("vector size: %lu\n", vectorSize(v));
    printf("index of 100: %d\n", vectorIndexOf(v, i32New(100)));
    printf("index of -10: %d\n", vectorIndexOf(v, i32New(-10)));
    printf("index of 2: %d\n", vectorIndexOf(v, i32New(2)));

    int *value = vectorFind(v, i32New(8));
    if (value) {
        printf("vector find 8: %d\n", *value);
    }

    printf("front: %d\n", *(int *)vectorFront(v));
    printf("back: %d\n", *(int *)vectorBack(v));

    vectorPop(v);

    printf("front: %d\n", *(int *)vectorFront(v));
    printf("back: %d\n", *(int *)vectorBack(v));

    vectorClear(v);

    vectorDestroy(v);
    return 0;
}
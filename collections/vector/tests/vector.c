#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    vector_push(v, i32(100));
    vector_push(v, str("luiz"));
    vector_push(v, vector());

    printf("%d\n", *(int *)vector_at(v, 0));
    printf("%s\n", (char *)vector_at(v, 1));

    Vector inside = vector_at(v, 2);

    vector_push(inside, i32(10));
    vector_push(inside, i32(10));
    vector_push(inside, i32(10));

    printf("%d\n", vector_size(inside));

    return 0;
}
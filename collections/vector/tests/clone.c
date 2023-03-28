#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(v, i32(i));
    }

    smart Vector v_clone = clone(v);

    for (i = 0; i < len(v_clone); i++) {
        int *value = vector_at(v_clone, i);
        *value *= 3;
    }

    print("original: {}\n", v);
    print("clone: {}\n", v_clone);

    return 0;
}
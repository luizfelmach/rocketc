#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(v, i32(i));
    }

    print("before: {}\n", v);
    vector_swap(v, 0, 9);
    print("after: {}\n", v);

    return 0;
}
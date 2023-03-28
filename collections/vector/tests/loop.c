#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 2000; i++) {
        vector_push(v, i32(i));
    }

    print("{}\n", v);

    return 0;
}
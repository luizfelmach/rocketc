#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Vector v = vector();

    int i, j;
    for (i = 0; i < 10; i++) {
        vector_push(v, vector());
        for (j = 0; j < 3; j++) {
            Vector f = vector_back(v);
            vector_push(f, f32(3.14 + j + i));
        }
    }

    print("{}\n", v);

    return 0;
}
#include <rocketc.h>
#include <std.h>
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

    smart Vector v_clone = clone(v);

    vector_pop(v_clone);
    vector_pop(v_clone);

    print("{}\n", v_clone);

    return 0;
}
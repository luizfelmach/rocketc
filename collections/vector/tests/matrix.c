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

    for (i = 0; i < vector_size(v); i++) {
        Vector f = vector_at(v, i);
        for (j = 0; j < vector_size(f); j++) {
            float *value = vector_at(f, j);
            printf("%.2f ", *value);
        }
        printf("\n");
    }

    return 0;
}
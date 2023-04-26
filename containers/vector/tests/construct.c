#include <rocketc.h>

int main() {
    smart Vector v = vector();

    int i;
    for (i = 0; i < 2000; i++) {
        vector_push(v, i32(i));
    }

    return 0;
}
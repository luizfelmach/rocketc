#include <rocketc.h>
#include <time.h>

int main() {
    smart Heap h = heap();

    int i;
    for (i = 0; i < 20; i++) {
        heap_insert(h, i32(rand() % 100));
    }

    print("{}\n", (h));
    return 0;
}
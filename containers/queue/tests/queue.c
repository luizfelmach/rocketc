#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Queue q = queue();

    queue_push(q, str("luiz"));
    queue_push(q, i32(10));
    queue_push(q, f32(2.1));

    queue_pop(q);
    queue_pop(q);
    // queue_pop(q);

    print("{}\n", q);

    return 0;
}
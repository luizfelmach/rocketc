#include <rocketc.h>
#include <stdio.h>

void stackReport(Stack s) {
    printf("size: %d\n", len(s));
    print("Top: {}\n\n", stack_top(s));
}

int main() {
    smart Stack s = stack();

    stack_push(s, i32(10));
    stack_push(s, i32(11));
    stack_push(s, i32(12));
    stack_push(s, i32(13));
    stack_push(s, i32(14));

    stack_pop(s);

    print("{}\n", s);
    return 0;
}
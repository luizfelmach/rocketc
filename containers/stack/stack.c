#include <list.h>
#include <mem.h>
#include <self.h>
#include <stack.h>
#include <std.h>

struct _stack {
    List data;
};

int stack_len(void *x) {
    Stack s = x;
    return len(s->data);
}

void stack_destroy(void *x) {
    Stack s = x;
    del(&s->data);
}

void stack_print(void *x) {
    Stack s = x;
    print("{}", s->data);
}

Self *stack_self() {
    Self *stack = self_new("stack");

    stack->len     = stack_len;
    stack->destroy = stack_destroy;
    stack->print   = stack_print;

    return stack;
}

Stack stack() {
    Stack s = memory_new(stack_self(), sizeof(struct _stack));
    s->data = list();
    return s;
}

void *stack_top(Stack s) {
    return list_back(s->data);
}

int stack_empty(Stack s) {
    return len(s->data) == 0;
}

void stack_push(Stack s, void *data) {
    list_push_back(s->data, data);
}

void stack_pop(Stack s) {
    void *data = list_pop_back(s->data);
    del(&data);
}
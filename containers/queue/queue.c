#include <list.h>
#include <mem.h>
#include <queue.h>
#include <self.h>
#include <std.h>

struct _queue {
    List data;
};

int queue_len(void *x) {
    Queue q = x;
    return len(q->data);
}

void queue_destroy(void *x) {
    Queue q = x;
    del(&q->data);
}

void queue_print(void *x) {
    Queue q = x;
    print("{}", q->data);
}

Self *queue_self() {
    Self *stack = self_new("queue");

    stack->len     = queue_len;
    stack->destroy = queue_destroy;
    stack->print   = queue_print;

    return stack;
}

Queue queue() {
    Queue q = memory_new(queue_self(), sizeof(struct _queue));
    q->data = list();
    return q;
}

void *queue_front(Queue q) {
    return list_front(q->data);
}

void *queue_back(Queue q) {
    return list_back(q->data);
}

int queue_empty(Queue q) {
    return len(q->data) == 0;
}

void queue_push(Queue q, void *data) {
    list_push_back(q->data, data);
}

void queue_pop(Queue q) {
    void *data = list_pop_front(q->data);
    del(&data);
}

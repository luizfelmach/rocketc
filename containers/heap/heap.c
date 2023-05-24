#include <heap.h>
#include <mem.h>
#include <std.h>
#include <vector.h>

struct _heap {
    Vector data;
};

void heap_destroy(void *ptr) {
    Heap heap = ptr;
    del(&heap->data);
}

void *heap_clone(void *ptr) {
    Heap h  = ptr;
    Heap c  = heap();
    c->data = clone(h->data);
    return c;
}

int heap_len(void *x) {
    Heap h = x;
    return len(h->data);
}

void heap_print(void *x) {
    Heap h = x;
    print("{}", h->data);
}

Self *heap_self() {
    Self *heap = self_new("heap");

    heap->destroy = heap_destroy;
    heap->clone   = heap_clone;
    heap->len     = heap_len;
    heap->print   = heap_print;

    return heap;
}

Heap heap() {
    Heap v = memory_new(heap_self(), sizeof(struct _heap));

    v->data = vector();

    return v;
}

int _heap_parent(int idx) {
    return (idx - 1) / 2;
}

int _heap_child1(int idx) {
    return 0;
}

int _heap_child2(int idx) {
    return 0;
}

void _heapify_up(Heap heap) {
    int last_idx   = len(heap->data) - 1;
    int parent_idx = _heap_parent(last_idx);

    while (last_idx) {
        void *child  = vector_at(heap->data, last_idx);
        void *parent = vector_at(heap->data, parent_idx);

        if (compare(child, parent) > 0) {
            vector_swap(heap->data, last_idx, parent_idx);
        }

        last_idx   = parent_idx;
        parent_idx = _heap_parent(parent_idx);
    }
}

void heap_insert(Heap heap, void *data) {
    vector_push(heap->data, data);
    _heapify_up(heap);
}

const void *heap_peek(Heap heap) {
    return vector_front(heap->data);
}

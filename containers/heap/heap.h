#ifndef HEAP_H
#define HEAP_H

typedef struct _heap *Heap;

Heap        heap();
void        heap_insert(Heap heap, void *data);
const void *heap_peek(Heap heap);

#endif
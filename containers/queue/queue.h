#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue *Queue;

Queue queue();
void *queue_front(Queue q);
void *queue_back(Queue q);
int   queue_empty(Queue q);
void  queue_push(Queue q, void *data);
void  queue_pop(Queue q);

#endif
#ifndef STACK_H
#define STACK_H

typedef struct _stack *Stack;

Stack stack();
void *stack_top(Stack s);
int   stack_empty(Stack s);
void  stack_push(Stack s, void *data);
void  stack_pop(Stack s);

#endif
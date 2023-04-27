#ifndef NODE_H
#define NODE_H

typedef struct _node {
    void *        value;
    struct _node *next;
} * Node;

Node node_new(void *value, Node next);
void node_destroy(Node node);

#endif
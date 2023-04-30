#ifndef NODE_H
#define NODE_H

typedef struct _node_list {
    void              *value;
    struct _node_list *next;
} *Node_List;

Node_List node_list_new(void *value, Node_List next);
void      node_list_destroy(Node_List node);

#endif
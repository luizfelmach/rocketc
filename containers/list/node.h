#ifndef NODE_H
#define NODE_H

typedef struct _node_forward_list {
    void                      *value;
    struct _node_forward_list *next;
} *Node_Forward_List;

typedef struct _node_list {
    void              *value;
    struct _node_list *prev;
    struct _node_list *next;
} *Node_List;

Node_Forward_List node_forward_list_new(void *value, Node_Forward_List next);
void              node_forward_list_destroy(Node_Forward_List node);

Node_List node_list_new(void *value, Node_List prev, Node_List next);
void      node_list_destroy(Node_List node);

#endif
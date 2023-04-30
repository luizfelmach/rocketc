#ifndef NODE_H
#define NODE_H

typedef struct _node_list {
    void              *value;
    struct _node_list *next;
} *Node_List;

typedef struct _node_dlist {
    void               *value;
    struct _node_dlist *prev;
    struct _node_dlist *next;
} *Node_DList;

Node_List node_list_new(void *value, Node_List next);
void      node_list_destroy(Node_List node);

Node_DList node_dlist_new(void *value, Node_DList prev, Node_DList next);
void       node_dlist_destroy(Node_DList node);

#endif
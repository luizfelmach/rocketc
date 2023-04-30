#include <node.h>
#include <stdlib.h>

Node_List node_list_new(void *value, Node_List next) {
    Node_List node = calloc(1, sizeof(struct _node_list));
    node->value    = value;
    node->next     = next;
    return node;
}

void node_list_destroy(Node_List node) {
    free(node);
}

Node_DList node_dlist_new(void *value, Node_DList prev, Node_DList next) {
    Node_DList node = calloc(1, sizeof(struct _node_dlist));
    node->value     = value;
    node->prev      = prev;
    node->next      = next;
    return node;
}

void node_dlist_destroy(Node_DList node) {
    free(node);
}

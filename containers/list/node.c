#include <node.h>
#include <stdlib.h>

Node_Forward_List node_forward_list_new(void *value, Node_Forward_List next) {
    Node_Forward_List node = calloc(1, sizeof(struct _node_forward_list));
    node->value            = value;
    node->next             = next;
    return node;
}

void node_forward_list_destroy(Node_Forward_List node) {
    free(node);
}

Node_List node_list_new(void *value, Node_List prev, Node_List next) {
    Node_List node = calloc(1, sizeof(struct _node_list));
    node->value    = value;
    node->prev     = prev;
    node->next     = next;
    return node;
}

void node_list_destroy(Node_List node) {
    free(node);
}

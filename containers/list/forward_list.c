#include <forward_list.h>
#include <mem.h>
#include <node.h>
#include <self.h>
#include <std.h>
#include <stdio.h>

struct _forward_list {
    int       size;
    Node_List head, tail;
};

void forward_list_print(void *x) {
    Forward_List list = x;

    Node_List cur = list->head;

    print("[");
    while (cur) {
        print("{}", cur->value);
        if (cur->next) print(", ");
        cur = cur->next;
    }
    print("]");
}

int forward_list_len(void *x) {
    Forward_List list = x;
    return list->size;
}

void forward_list_destroy(void *x) {
    Forward_List list = x;

    Node_List cur = list->head;
    while (cur) {
        Node_List aux = cur->next;
        del(&cur->value);
        node_list_destroy(cur);
        cur = aux;
    }
}

Self *forward_list_self() {
    Self *list = self_new("forward_list");

    list->print   = forward_list_print;
    list->destroy = forward_list_destroy;
    list->len     = forward_list_len;

    return list;
}

Forward_List forward_list() {
    Forward_List list = memory_new(forward_list_self(), sizeof(struct _forward_list));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void *forward_list_front(Forward_List list) {
    if (!list->head) return NULL;
    return list->head->value;
}

void *forward_list_back(Forward_List list) {
    if (!list->tail) return NULL;
    return list->tail->value;
}

void forward_list_push_front(Forward_List list, void *data) {
    list->head = node_list_new(data, list->head);
    if (list->size == 0) {
        list->tail = list->head;
    }
    list->size += 1;
}

void *forward_list_pop_front(Forward_List list) {
    if (!list->head) {
        printf("error: list is empty\n");
        exit(1);
    }
    void *data = list->head->value;

    Node_List n = list->head;
    list->head  = list->head->next;
    node_list_destroy(n);

    if (list->size == 1) {
        list->tail = list->head;
    }
    list->size -= 1;

    return data;
}

void forward_list_push_back(Forward_List list, void *data) {
    Node_List n = node_list_new(data, NULL);

    if (list->size == 0) {
        list->head = list->tail = n;
    } else {
        list->tail = list->tail->next = n;
    }

    list->size += 1;
}

void *forward_list_pop_back(Forward_List list) {
    void *data = NULL;

    if (!list->head) {
        printf("error: list is empty\n");
        exit(1);
    }

    if (list->size == 1) {
        data = list->head->value;
        node_list_destroy(list->head);
        list->head = list->tail = NULL;
    }

    Node_List current  = list->head;
    Node_List previous = NULL;

    while (current) {
        if (current->next == NULL) {
            previous->next = NULL;
            data           = current->value;
            node_list_destroy(current);
            list->tail = previous;
            break;
        }
        previous = current;
        current  = current->next;
    }

    list->size -= 1;

    return data;
}

void forward_list_clear(Forward_List list) {
    int size = list->size;
    int i;
    for (i = 0; i < size; i++) {
        void *data = forward_list_pop_front(list);
        del(&data);
    }
}

void *forward_list_find(Forward_List list, void *data) {
    void     *target  = NULL;
    Node_List current = list->head;

    while (current) {
        if (!compare(current->value, data)) {
            target = current->value;
            break;
        }
        current = current->next;
    }
    del(&data);

    return target;
}

#include <list.h>
#include <node.h>
#include <self.h>
#include <std.h>
#include <stdio.h>
#include <stdlib.h>

struct _list {
    int        size;
    Node_DList head, tail;
};

void list_print(void *x) {
    List list = x;

    Node_DList cur = list->head;

    print("[");
    while (cur) {
        print("{}", cur->value);
        if (cur->next) print(", ");
        cur = cur->next;
    }
    print("]");
}

int list_len(void *x) {
    List list = x;
    return list->size;
}

void list_destroy(void *x) {
    List list = x;

    Node_DList cur = list->head;
    while (cur) {
        Node_DList aux = cur->next;
        del(&cur->value);
        node_dlist_destroy(cur);
        cur = aux;
    }
}

Self *list_self() {
    Self *list = self_new("list");

    list->print   = list_print;
    list->destroy = list_destroy;
    list->len     = list_len;

    return list;
}

List list() {
    List list = memory_new(list_self(), sizeof(struct _list));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void *list_front(List list) {
    if (!list->head) return NULL;
    return list->head->value;
}

void *list_back(List list) {
    if (!list->tail) return NULL;
    return list->tail->value;
}

void list_push_front(List list, void *data) {
    Node_DList cur = list->head;
    list->head     = node_dlist_new(data, NULL, list->head);
    if (list->size == 0) {
        list->tail = list->head;
    } else {
        cur->prev = list->head;
    }
    list->size += 1;
}

void *list_pop_front(List list) {
    if (!list->head) {
        printf("error: list is empty\n");
        exit(1);
    }
    void *data = list->head->value;

    Node_DList n     = list->head;
    list->head       = list->head->next;
    list->head->prev = NULL;
    node_dlist_destroy(n);

    if (list->size == 1) {
        list->tail = list->head;
    }
    list->size -= 1;

    return data;
}

void list_push_back(List list, void *data) {
    Node_DList n = node_dlist_new(data, list->tail, NULL);

    if (list->size == 0) {
        list->head = list->tail = n;
    } else {
        list->tail = list->tail->next = n;
    }

    list->size += 1;
}

void *list_pop_back(List list) {
    void *data = NULL;

    if (!list->head) {
        printf("error: list is empty\n");
        exit(1);
    }

    if (list->size == 1) {
        data = list->head->value;
        node_dlist_destroy(list->head);
        list->head = list->tail = NULL;
    } else {
        Node_DList penultimate = list->tail->prev;
        penultimate->next      = NULL;
        data                   = list->tail->value;
        node_dlist_destroy(list->tail);
        list->tail = penultimate;
    }

    list->size -= 1;

    return data;
}

void list_clear(List list) {
    int size = list->size;
    int i;
    for (i = 0; i < size; i++) {
        void *data = list_pop_front(list);
        del(&data);
    }
}

void *list_find(List list, void *data) {
    void      *target  = NULL;
    Node_DList current = list->head;

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

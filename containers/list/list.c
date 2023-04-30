#include <list.h>
#include <mem.h>
#include <node.h>
#include <self.h>
#include <std.h>
#include <stdio.h>

struct _list {
    int  size;
    Node_List head, tail;
};

void list_print(void *x) {
    List list = x;

    Node_List cur = list->head;

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

    Node_List cur = list->head;
    while (cur) {
        Node_List aux = cur->next;
        del(&cur->value);
        node_list_destroy(cur);
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
    list->head = node_list_new(data, list->head);
    if (list->size == 0) {
        list->tail = list->head;
    }
    list->size += 1;
}

void *list_pop_front(List list) {
    if (!list->head) {
        printf("error: list is empty\n");
        exit(1);
    }
    void *data = list->head->value;

    Node_List n     = list->head;
    list->head = list->head->next;
    node_list_destroy(n);

    if (list->size == 1) {
        list->tail = list->head;
    }
    list->size -= 1;

    return data;
}

void list_push_back(List list, void *data) {
    Node_List n = node_list_new(data, NULL);

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

void list_clear(List list) {
    int size = list->size;
    int i;
    for (i = 0; i < size; i++) {
        void *data = list_pop_front(list);
        del(&data);
    }
}

void *list_find(List list, void *data) {
    void *target  = NULL;
    Node_List  current = list->head;

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

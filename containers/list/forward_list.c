#include <forward_list.h>
#include <mem.h>
#include <node.h>
#include <self.h>
#include <std.h>
#include <stdio.h>

struct _forward_list {
    int               size;
    Node_Forward_List head, tail;
};

void forward_list_print(void *x) {
    Forward_List      fl = x;
    Node_Forward_List n  = fl->head;

    print("[");
    while (n) {
        print("{}", n->value);
        if (n->next) print(", ");
        n = n->next;
    }
    print("]");
}

int forward_list_len(void *x) {
    Forward_List fl = x;
    return fl->size;
}

void forward_list_destroy(void *x) {
    Forward_List      fl = x;
    Node_Forward_List n  = fl->head;

    while (n) {
        Node_Forward_List aux = n->next;
        del(&n->value);
        node_forward_list_destroy(n);
        n = aux;
    }
}

Self *forward_list_self() {
    Self *fl = self_new("forward_list");

    fl->print   = forward_list_print;
    fl->destroy = forward_list_destroy;
    fl->len     = forward_list_len;

    return fl;
}

Forward_List forward_list() {
    Forward_List fl = memory_new(forward_list_self(), sizeof(struct _forward_list));

    fl->size = 0;
    fl->head = NULL;
    fl->tail = NULL;

    return fl;
}

void *forward_list_front(Forward_List fl) {
    if (!fl->head) {
        return NULL;
    }
    return fl->head->value;
}

void *forward_list_back(Forward_List fl) {
    if (!fl->tail) {
        return NULL;
    }
    return fl->tail->value;
}

void forward_list_push_front(Forward_List fl, void *data) {
    fl->head = node_forward_list_new(data, fl->head);

    if (fl->size == 0) {
        fl->tail = fl->head;
    }

    fl->size += 1;
}

void *forward_list_pop_front(Forward_List fl) {
    if (!fl->head) {
        printf("IndexError: pop from empty forward list.\n");
        exit(1);
    }

    void             *data = fl->head->value;
    Node_Forward_List n    = fl->head;
    fl->head               = fl->head->next;
    fl->size -= 1;
    node_forward_list_destroy(n);

    if (fl->size == 0) {
        fl->tail = fl->head;
    }

    return data;
}

void forward_list_push_back(Forward_List fl, void *data) {
    Node_Forward_List n = node_forward_list_new(data, NULL);

    if (fl->size == 0) {
        fl->head = fl->tail = n;
    } else {
        fl->tail = fl->tail->next = n;
    }

    fl->size += 1;
}

void *forward_list_pop_back(Forward_List fl) {
    if (!fl->head) {
        printf("IndexError: pop from empty forward list.\n");
        exit(1);
    }

    void *data = NULL;

    if (fl->size == 1) {
        data = fl->head->value;
        node_forward_list_destroy(fl->head);
        fl->head = fl->tail = NULL;
    }

    Node_Forward_List n    = fl->head;
    Node_Forward_List prev = NULL;

    while (n) {
        if (n->next == NULL) {
            prev->next = NULL;
            data       = n->value;
            node_forward_list_destroy(n);
            fl->tail = prev;
            break;
        }
        prev = n;
        n    = n->next;
    }

    fl->size -= 1;

    return data;
}

void forward_list_clear(Forward_List fl) {
    int size = fl->size;
    int i;
    for (i = 0; i < size; i++) {
        void *data = forward_list_pop_front(fl);
        del(&data);
    }
}

void *forward_list_find(Forward_List fl, void *data) {
    void             *target = NULL;
    Node_Forward_List n      = fl->head;

    while (n) {
        if (!compare(n->value, data)) {
            target = n->value;
            break;
        }
        n = n->next;
    }

    del(&data);

    return target;
}

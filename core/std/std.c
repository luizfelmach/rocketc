#include <mem.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *clone(void *x) {
    Memory m = memory_get(x);
    if (!m->self->clone) {
        printf("TypeError: object of type '%s' has no clone().\n", m->self->key);
        exit(1);
    }
    return m->self->clone(x);
}

int compare(void *a, void *b) {
    Memory m1 = memory_get(a);
    Memory m2 = memory_get(b);

    if (strcmp(m1->self->key, m2->self->key)) {
        return -100;
    }

    if (!m1->self->compare || !m2->self->compare) {
        printf("TypeError: object of type '%s' has no compare().\n", m1->self->key);
        exit(1);
    }

    return m1->self->compare(a, b);
}

void del(void **x) {
    memory_destroy(*x);
    *x = NULL;
}

int len(void *x) {
    Memory m = memory_get(x);
    if (!m->self->len) {
        printf("TypeError: object of type '%s' has no len().\n", m->self->key);
        exit(1);
    }
    return m->self->len(x);
}

void nothing(void *ptr) {
}

void dump(void *x) {
    Memory m = memory_get(x);
    if (!m->self->print) {
        printf("TypeError: object of type '%s' has no print().\n", m->self->key);
        exit(1);
    }
    return m->self->print(x);
}

void print(char *fmt, ...) {
    char   *k = fmt;
    va_list args;

    va_start(args, fmt);

    while (*k != '\0') {
        if (*k == '{') {
            void *arg = va_arg(args, void *);
            dump(arg);
            k += 2;
        } else {
            printf("%c", *k);
            k += 1;
        }
    }

    va_end(args);
}

char *to_string(void *x) {
    Memory m = memory_get(x);
    if (!m->self->to_string) {
        printf("TypeError: object of type '%s' has no to_string().\n", m->self->key);
        exit(1);
    }
    return m->self->to_string(x);
}
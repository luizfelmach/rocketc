#include <metadata.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *clone(void *x) {
    Meta m = metadata_get(x);
    if (!m->self->clone) {
        printf("error: %s type is not cloneable.\n", m->self->type_name);
        exit(1);
    }
    return m->self->clone(x);
}

int compare(void *a, void *b) {
    Meta m1 = metadata_get(a);
    Meta m2 = metadata_get(b);

    if (strcmp(m1->self->type_name, m2->self->type_name)) {
        return -100;
    }

    if (!m1->self->compare || !m2->self->compare) {
        printf("error: %s type is not comparable.\n", m1->self->type_name);
        exit(1);
    }

    return m1->self->compare(a, b);
}

void del(void **x) {
    metadata_destroy(*x);
    *x = NULL;
}

int len(void *x) {
    Meta m = metadata_get(x);
    return m->self->len(x);
}

void nothing(void *ptr) {
}

void dump(void *x) {
    Meta m = metadata_get(x);
    return m->self->print(x);
}

void set_format_print(void *x, char *fmt) {
    Meta m = metadata_get(x);
    self_format_print(m->self, fmt);
}

char *format_print(void *x) {
    Meta m = metadata_get(x);
    return m->self->format_print;
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
    Meta m = metadata_get(x);
    if (!m->self->to_string) {
        printf("error: object is not able to string.\n");
        exit(1);
    }
    return m->self->to_string(x);
}
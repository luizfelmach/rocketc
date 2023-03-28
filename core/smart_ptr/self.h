#ifndef SELF_H
#define SELF_H

typedef int (*compare_fn)(void *, void *);
typedef void (*destroy_fn)(void *);
typedef char *(*to_string_fn)(void *);
typedef void *(*clone_fn)(void *);
typedef int (*len_fn)(void *);
typedef void (*print_fn)(void *);

struct _self {
    char         type_name[256];
    char         format_print[18];
    compare_fn   compare;
    destroy_fn   destroy;
    to_string_fn to_string;
    clone_fn     clone;
    len_fn       len;
    print_fn     print;
};

typedef struct _self *Self;

Self self_new(char *type_name, char *format_string);
void self_destroy(Self self);

void self_type_name(Self self, char *type_name);
void self_format_print(Self self, char *format_print);

#endif  // SELF_H

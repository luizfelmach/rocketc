#ifndef SELF_H
#define SELF_H

typedef void (*print_fn)(void *);
typedef int (*compare_fn)(void *, void *);
typedef void (*destroy_fn)(void *);

struct _self {
    char       type_name[256];
    print_fn   print;
    compare_fn compare;
    destroy_fn destroy;
};

typedef struct _self *Self;

Self self_new(char *type_name);
void self_destroy(Self self);

#endif  // SELF_H

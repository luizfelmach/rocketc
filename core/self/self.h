#ifndef SELF_H
#define SELF_H

typedef int (*compare_fn)(void *, void *);
typedef void (*destroy_fn)(void *);
typedef char *(*to_string_fn)(void *);
typedef void *(*clone_fn)(void *);
typedef int (*len_fn)(void *);
typedef void (*print_fn)(void *);

typedef struct  {
    char         key[256];
    compare_fn   compare;
    destroy_fn   destroy;
    to_string_fn to_string;
    clone_fn     clone;
    len_fn       len;
    print_fn     print;
} Self;

Self *self_new(char *key);

#endif  // SELF_H

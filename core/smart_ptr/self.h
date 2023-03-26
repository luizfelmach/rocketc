#ifndef SELF_H
#define SELF_H

typedef int (*compare_fn)(void *, void *);
typedef void (*destroy_fn)(void *);
typedef char *(*to_string_fn)(void *);
typedef void *(*clone_fn)(void *);
typedef void *(*it_fn)(void *, int i);
typedef void *(*it_begin_fn)(void *);

struct _self {
    char         type_name[256];
    compare_fn   compare;
    destroy_fn   destroy;
    to_string_fn to_string;
    clone_fn     clone;
    it_fn        it;
    it_begin_fn  it_begin;
};

typedef struct _self *Self;

Self self_new(char *type_name);
void self_destroy(Self self);

#endif  // SELF_H

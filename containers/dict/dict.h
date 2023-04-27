#ifndef DICT_H
#define DICT_H

typedef struct _dict *Dict;

Dict  dict(int n, ...);
void *dict_get(Dict d, void *key);

#endif

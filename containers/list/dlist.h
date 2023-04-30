#ifndef DLIST_H
#define DLIST_H

typedef struct _dlist *DList;

DList dlist();
void *dlist_front(DList dlist);
void *dlist_back(DList dlist);
void  dlist_push_front(DList dlist, void *data);
void *dlist_pop_front(DList dlist);
void  dlist_push_back(DList dlist, void *data);
void *dlist_pop_back(DList dlist);
void  dlist_clear(DList dlist);
void *dlist_find(DList dlist, void *data);

#endif  // DLIST_H
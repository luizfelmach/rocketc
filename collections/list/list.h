#ifndef LIST_H
#define LIST_H

#include <self.h>

typedef struct _list *List;
typedef void         *generic;  // Change to core // todo

List    listNew(Self self);
generic listFront(List list);
generic listBack(List list);
void    listPushFront(List list, generic data);
void    listPopFront(List list);
void    listPushBack(List list, generic data);
void    listPopBack(List list);
void    listClear(List list);
int     listSize(List list);
generic listFind(List list, generic data);
void    listDestroy(List list);

#endif  // LIST_H
#ifndef LIST_H
#define LIST_H

typedef struct _list *List;

List  list();
void *list_front(List list);
void *list_back(List list);
void  list_push_front(List list, void *data);
void *list_pop_front(List list);
void  list_push_back(List list, void *data);
void *list_pop_back(List list);
void  list_clear(List list);
void *list_find(List list, void *data);

#endif  // LIST_H
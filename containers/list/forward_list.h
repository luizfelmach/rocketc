#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

typedef struct _forward_list *Forward_List;

Forward_List forward_list();
void        *forward_list_front(Forward_List fl);
void        *forward_list_back(Forward_List fl);
void         forward_list_push_front(Forward_List fl, void *data);
void        *forward_list_pop_front(Forward_List fl);
void         forward_list_push_back(Forward_List fl, void *data);
void        *forward_list_pop_back(Forward_List fl);
void         forward_list_clear(Forward_List fl);
void        *forward_list_find(Forward_List fl, void *data);

#endif  // FORWARD_LIST_H

#include <rocketc.h>
#include <stdio.h>

int main() {
    smart Forward_List l = forward_list();

    forward_list_push_back(l, str("felipe"));
    forward_list_push_back(l, str("machado"));
    forward_list_push_front(l, str("luiz"));

    print("{}\n", l);  // ['luiz', 'felipe', 'machado']

    return 0;
}
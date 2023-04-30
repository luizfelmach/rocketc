#include <rocketc.h>
#include <stdio.h>

int main() {
    smart DList l = dlist();

    dlist_push_front(l, str("felipe"));
    dlist_push_back(l, str("machado"));
    dlist_push_front(l, str("luiz"));

    print("{}\n", l);  // ['luiz', 'felipe', 'machado']

    return 0;
}
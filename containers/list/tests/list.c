#include <rocketc.h>
#include <stdio.h>

int main() {
    smart List l = list();

    list_push_back(l, str("felipe"));
    list_push_back(l, str("machado"));
    list_push_front(l, str("luiz"));

    print("{}\n", l);  // ['luiz', 'felipe', 'machado']

    return 0;
}
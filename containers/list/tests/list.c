#include <rocketc.h>
#include <stdio.h>

int main() {
    smart List l = list();

    list_push_back(l, str("luiz"));
    list_push_back(l, str("felipe"));
    list_push_back(l, str("machado"));

    print("{}\n", list_find(l, str("luiz")));

    // list_clear(l);

    // print("{}\n", list_pop_front(l));

    // print("{}\n", l);
    // print("front: {}\n", list_front(l));
    // print("back: {}\n", list_back(l));

    // print("{}\n", list_pop_front(l));

    // print("{}\n", l);
    // print("front: {}\n", list_front(l));
    // print("back: {}\n", list_back(l));

    // print("{}\n", list_pop_front(l));

    // print("{}\n", l);
    // print("front: {}\n", list_front(l));
    // print("back: {}\n", list_back(l));

    // print("{}\n", list_pop_front(l));

    // print("{}\n", l);
    // print("front: {}\n", list_front(l));
    // print("back: {}\n", list_back(l));

    return 0;
}
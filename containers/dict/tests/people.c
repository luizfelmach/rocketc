#include <rocketc.h>

Dict people(char *name, int age, float height) {
    // clang-format off
    Dict people = dict(3, 
        pair(str("name"), str(name)),
        pair(str("age"), i32(age)),
        pair(str("height"), f32(height))
    );

    return people;
}

int main() {

    smart Dict p1 = people("Luiz Felipe Machado", 85, 1.83);

    print("p1: {}\n\n", p1);
    print("name: {}\n", dict_get(p1, str("name")));
    print("age: {}\n", dict_get(p1, str("age")));
    print("height: {}\n", dict_get(p1, str("height")));
    print("undefined attr: {}\n", dict_get(p1, str("test")));

    return 0;
}
#include <rocketc.h>

int main() {
    // clang-format off
    smart Dict student = dict(4, 
        pair(str("name"), str("luiz felipe machado")),
        pair(str("year"), i32(2020)),
        pair(str("grades"), vector()),
        pair(str("city"), dict(1,
            pair(str("street"), str(""))
        ))
    );

    smart Dict student_clone = clone(student);

    int i;
    for (i = 0; i < 10; i++) {
        vector_push(dict_get(student, str("grades")), i32(10));
    }

    int *year = dict_get(student, str("year"));
    *year = 2023;

    print("{}\n", student);
    print("{}\n", student_clone);
    print("{}\n", dict_get(student, str("ksdljfjksdf")));

    return 0;
}
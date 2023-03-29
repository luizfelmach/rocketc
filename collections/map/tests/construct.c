#include <rocketc.h>

int main() {
    // clang-format off
    smart Map student = map(4, 
        pair(str("name"), str("luiz felipe machado")),
        pair(str("year"), i32(18)),
        pair(str("grades"), vector()),
        pair(str("city"), map(1,
            pair(str("street"), str(""))
        ))
    );

    print("{}\n", student);

    return 0;
}
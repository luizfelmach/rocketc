#include <rocketc.h>
#include <stdio.h>

int main() {
    smart int*   a = i32(200);
    smart float* b = f32(3.14159);
    smart char*  c = str("Luiz Feli %.2f Machado", *b);

    set_format_print(a, "%100d");

    print("a = {}, b = {}, c = {}\n", a, b, c);

    return 0;
}
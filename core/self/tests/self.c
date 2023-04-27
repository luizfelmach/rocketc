#include <rocketc.h>
#include <stdio.h>

int main() {
    Self *self = self_new("string");

    printf("%s\n", self->key);
    printf("%d\n", self_exists(self));
    return 0;
}

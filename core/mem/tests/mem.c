#include <stdio.h>
#include <rocketc.h>

int main() {
    Self *self = self_new("string");
    
    smart void *value = memory_new(self, 4);
    return 0;
}

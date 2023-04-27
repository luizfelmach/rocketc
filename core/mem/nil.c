#include <nil.h>
#include <self.h>
#include <stdio.h>

void nil_print(void *x) {
    printf("(nil)");
}

Self *nil() {
    Self *nil = self_new("nil");

    nil->print = nil_print;

    return nil;
}

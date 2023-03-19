#include <stdio.h>
#include <stdlib.h>
#include <str.h>
#include <string.h>

char *strNew(char *x) {
    return strdup(x);
}

void strPrint(void *x) {
    printf("%s", (char *)x);
}

Self strSelf() {
    Self str     = selfNew("str");
    str->destroy = free;
    str->compare = (compareFn)strcmp;
    str->print   = (printFn)strPrint;
    return str;
}
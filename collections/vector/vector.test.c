#include <rocketc.h>
#include <stdio.h>

int main() {
    Vector v = vectorNew(i32Self());
    vectorPush(v, i32New(120));
    vectorShow(v);
    vectorDestroy(v);
    return 0;
}
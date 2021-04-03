#include <stdio.h>
extern int count;

int main() {
    foo(24);
    printf("%d", count);
    return 0;
}
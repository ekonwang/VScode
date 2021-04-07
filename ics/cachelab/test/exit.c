#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main() {
    int heap_id = 1342433553;
    int s = 3, S = 1 << s;
    int mask = ~(-1 << s);
    int col = heap_id & ~(-1 << s);
    printf("%d %d %x", col, heap_id % S, mask);
    exit(123);
    return 0;
}
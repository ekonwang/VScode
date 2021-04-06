#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main() {
    for(int i = 0; i < 10; ++i) {
        printf("%s", i % 5?"":"y\n");
    }
    exit(123);
    return 0;
}
#include "printResult.h"
void printResult(int s[], int n, char* str) {
    printf("%s", str);
    int i;
    for(int i = 0; i < n; i++) {
        printf("%5d", s[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *opt = "s:E:b:";
    int i = 0;
    printf("\nargc: %d\n", argc);
    while( (i = getopt(argc, argv, opt)) != -1 ){
        printf("\nargment u input: %c", (char)i);
        printf("\n value : %d", atoi(optarg) + 1);
    }
    return 0;
}
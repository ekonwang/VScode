#include "stdio.h"  

extern char** environ;   /*C库定义的全局变量,环境变量字符串数组的起始地址*/  

int main(int argc, char* argv[])  

{  

    int i;  

    char** p = environ;  

    for(i=0; i<argc; i++)  

        printf("argv[%d]: %s\n", i, argv[i]);  

    printf("\n\nEnviroment Varibles\n\n");  

    while(*p != NULL)  

        printf("%s\n", *(p++));  

    return 0;  
}
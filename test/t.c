#include "stdio.h"  

extern char** environ;   /*C库定义的全局变量,环境变量字符串数组的起始地址*/  

int main(int argc, char* argv[])  

{  

    int i;  

    char** p = argv;  

    if(!argc) 
	
	printf("\n%d\n", argc);

    while(*p != NULL)  

        printf("%s\n", *(p++));  

    return 0;  
}

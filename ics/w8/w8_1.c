#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define Fsize 100

int main(int argc, char *argv[]){
    int fd = open(argv[1], O_RDWR);
    if(fd == -1){
        perror("open fails.\n");
        exit(0);
    }
    long long re = (long long)mmap(0, Fsize, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(re == -1){
        perror("mmap");
        exit(0);
    }
    char*ch = (char*)re;
    if(*ch == 'H') *ch = 'J';
    while(*ch != '\n' && (ch - (char*)re) < Fsize){
        printf("%c", *ch);
        ch++;
    }

    printf("\n");
    munmap((void*)re, Fsize);
    exit(0);
}
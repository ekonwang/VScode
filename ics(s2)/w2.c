#include <stdio.h>

void *effective_memset(void *s, int c, size_t n){
    size_t i, limit = n - 7, cnt = 0;
    char *schar;
    union{
        unsigned long long a;
        unsigned char b[8];
    }un;
    unsigned char unb = (unsigned char) c;
    for(i = 0; i < 8; i++) {
        un.b[i] = unb;
    }
    unsigned long long una = un.a;



    schar = s;
    while((unsigned long long)schar % 8){     //避免段错误
        *schar++ = unb;
        cnt ++;
    }
    unsigned long long *sll = schar;          //函数主体，字赋值而非字节赋值
    while(cnt < limit) {
        *sll++ = una;
        cnt += 8;
    }
    schar = sll;
    while(cnt < n) {
        *schar++ = unb;
        cnt ++;
    }
}

int main() {
    int a[5] = {0, 1, 3, 4, 5};
    effective_memset(a, 0, sizeof(a));
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
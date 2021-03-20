#include <iostream>
#include <time.h>
using namespace std;

void *effective_memset(void *s, int c, size_t n){
    size_t i, limit = n - 7, cnt = 0;
    unsigned char *schar;
    union{
        unsigned long long a;
        unsigned char b[8];
    }un;
    unsigned char unb = (unsigned char) c;
    for(i = 0; i < 8; i++) {
        un.b[i] = unb;
    }
    unsigned long long una = un.a;



    schar = (unsigned char*)s;
    while((unsigned long long)schar % 8){     //避免段错误
        *schar++ = unb;
        cnt ++;
    }
    unsigned long long *sll = (unsigned long long *)schar;          //函数主体，字赋值而非字节赋值
    while(cnt < limit) {
        *sll++ = una;
        cnt += 8;
    }
    schar = (unsigned char *)sll;
    while(cnt < n) {
        *schar++ = unb;
        cnt ++;
    }
    return s;
}

void *basic_memset(void *s, int c, size_t n) {
    size_t cnt = 0;
    unsigned char *schar = (unsigned char *)s;
    while(cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }
    return s;
}

#define N 400000000
#define M 5000000

int main() {
    ios::sync_with_stdio(0);
    int *a = new int[N];
    //int a[N];
    if(a == NULL) {
        cout << "application failed" << endl;
    }
    clock_t bc, ec;
    srand(time(0));
    for(int i = 0; i < N; i++) {
        a[i] = rand();
    }
    bc = clock();
    effective_memset(a, 0, N * sizeof(int));
    ec = clock();
    cout << "effective memset: " << (double)(ec - bc) << " ms" << endl;
    for(int i = 0; i < N; i++) {
        if(a[i]) {cout << "memset failed." << endl; break;}
    }

    bc = clock();
    basic_memset(a, 0, N * sizeof(int));
    ec = clock();
    cout << "basic memset: " << (double)(ec - bc) << " ms" << endl;
    for(int i = 0; i < N; i++) {
        if(a[i]) {cout << "memset failed." << endl; break;}
    }
    delete []a;
    return 0;
}
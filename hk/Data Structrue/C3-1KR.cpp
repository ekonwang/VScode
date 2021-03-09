#include<iostream>
using namespace std;
#define Rehash(a,b,h) ((((h)-(a)*d)<<1)+(b))
int KR(char *x, int m, char *y, int n){
    int d, hx, hy, i, j;
    for(d = i = 1; i < m; i++)
        d = d << 1;
    for(hy = hx = i = 0; i < m; i++){
        hx = (hx << 1) + x[i];
        hy = (hy << 1) + y[i];
    }
    for(j = 0; j <= n - m; j++){
        if(hx == hy && memcmp(x, y + j, m) == 0)
            return j;
        hy = Rehash(y[j],y[j+m],hy);
    }
    return -1;
}
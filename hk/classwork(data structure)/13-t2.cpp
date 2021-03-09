#include<iostream>
using namespace std;
#define N 20
int a[N] = {0};
int m[N][N] = {0};
int fd(int x){
    if (a[x] == x) return x;
    else return a[x] = fd(a[x]);
}
void combine(int x, int y){
    a[fd(y)] = fd(x);
}
int main(){
    int n, x, y, val, max = 0, i = 0;
    int b[N] = {0};
    for(int j = 0; j < N; j ++) a[j] = j;
    while(cin >> val){
        m[0][i++] = val;
        if(cin.get() == '\n') break;
    }
    n = i;
    for(int j = 1; j < n; j++){
        for(int k = 0; k < n; k++){
            cin >> val;
            m[j][k] = val;
        }
    }
    
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(m[j][k] == 1) combine(j, k);
        }
    }
    for(int j = 0; j < n; j++){
        b[fd(j)] ++;
    }
    for(int j = 0; j < n; j++){
        max = b[j] > max ? b[j]:max;
    }
    cout << max << endl;
    system("pause");
    return 0;
}

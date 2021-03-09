#include<bits/stdc++.h>
#define N 4000
using namespace std;
int a[N + 10], high;

void imul(int x){
    for(int i = 0; i < N; i++) a[i] = a[i] * x; //log1 + log2 + log3
    for(int i = 0; i < N; i++){
        a[i + 1] += a[i] / 10;
        a[i] = a[i] % 10;
    }
}
void factorial(int n){
    memset(a, 0, sizeof(a));
    a[0] = 1;
    for(int k = 2; k <= n; k++){
        for(int i = 0; i < N; i++) a[i] = a[i] * k; //log1 + log2 + log3
        for(int i = 0; i < N; i++){
            a[i + 1] += a[i] / 10;
            a[i] = a[i] % 10;
        }
    }
    high = N;
    while(!a[high]) high--;
}
int get_ans(int b){
    int count = 0;
    for(int i = 0; i <= high; i++){
        if(a[i] == b) count ++;
    }
    return count;
}
int main(){
    int n, p, q;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> q;
        factorial(p);
        cout << get_ans(q) << endl;
        /* for(int i = high; i >= 0; i--) cout << a[i]; */
    }
    //system("pause");
    return 0;
}

//log1 出错先检查低级错误

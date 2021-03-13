#include<bits/stdc++.h>
using namespace std;
#define N 1001
int a[N], n, m, x, y, r;
int fd(int x){
    if(a[x] == x)return x;
    else a[x] = fd(a[x]);
    return a[x];
}
void combine(int x, int y){
    a[fd(x)] = fd(y);
}
void test(int cts){
    r = -1;
    cin >> m;
    for(int i = 1; i <= cts; i++){
        a[i] = i;
    }
    for(int j = 0; j < m; j++){
        cin >> x >> y;
        combine(x, y);
    }
    for(int k = 1; k <= cts; k++){
        if(a[k] == k) r++;
    }
    cout << r << endl;
}
int main(){
    while(cin >> n){ 
        if(!n) break;
        test(n);
    }
    //system("pause");
    return 0;
}

#include<iostream>
using namespace std;
int get_mid(int a[], int n, int b[], int m){
    int i = 0, j = 0, k, res = 0, mid = (m + n + 1)/2;
    for(k = 0; k < mid; k++){
        if(a[i] < b[j]) { res = a[i++]; }
        else {res = b[j++];}
    }
    return res;
}
int main(){
    int n, m, val, i, *a, *b;
    cin >> n >> m;           //输入两个序列的长度
    a = new int[n];
    b = new int[m];
    for(i = 0; i < n; i++){
        cin >> val;
        a[i] = val;
    }
    for(i = 0; i < m; i++){
        cin >> val;
        b[i] = val;
    }
    cout << get_mid(a, n, b, m);
    system("pause");
    return 0;
}

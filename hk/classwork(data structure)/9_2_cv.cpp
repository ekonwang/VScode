#include<iostream>
using namespace std;
void sort(int a[], int n, int s = 0){
    int t, p;
    for(int i = s; i < n; i++){
        p = i;
        for(int j = i; j < n; j++){
            if(a[p] > a[j]) p = j;
        }
        t = a[i];
        a[i] = a[p];
        a[p] = t;
    }
}
void sift_up(int *a, int b, int k){
    int j = k - b, i = (j - 1)/2, t = a[j + b];
    for(;i >= 0; i = (j - 1)/2){
        if(a[j + b] < a[i + b]){
            a[j + b] = a[i + b];
            j = i;
        }else break;
    }
    a[j + b] = t;
}
int main(){
    int n, *a, res = 0;
    cin >> n;
    a = new int[2*n - 1];

    /* for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << '\t';
    cout << endl;
    cin >> a[n];
    sift_up(a, 1, n);
    for(int i = 0; i <= n; i++) cout << a[i] << '\t'; */
 
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, n);
    for(int i = 0; i < n - 1; i++){
        a[n + i] = a[i*2] + a[i*2 + 1];
        res += a[n+i];
        sort(a, n + i + 1, 2 * i + 2);

        for(int j = 2*i; j <= n + i; j++) cout << a[j] << '\t';
        cout << endl; 
    }
    res += a[2*n - 2];
    cout << res;  
    system("pause");
    return 0;
}
//log1 sort函数写成降序
//log2 sift函数a[j] = t; 写成a[i] = t;
//log3 sift_up函数似乎不起作用
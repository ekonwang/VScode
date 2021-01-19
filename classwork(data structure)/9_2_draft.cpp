#include<bits/stdc++.h>
using namespace std;
void sift_down(int a[], int k, int n, int b = 0){
    n -= b;
    int j = k - b, i = 2 * j + 1, t;
    for(; i < n; i = 2 * j + 1){
        if(i < n - 1 && a[i + 1 + b] > a[i + b]) i++;
        if(a[i + b] > a[j + b]){
            t = a[j + b];
            a[j + b] = a[i + b];
            a[i + b] = t;
            j = i;
        }else break;
    }
}
void heap_sort(int a[], int n, int b = 0){
    int t;
    n -= b;
    for(int r = (n - 1)/2; r >= 0; r--) sift_down(a, r + b, n + b, b);

    /* for(int i = 0; i < n; i++) cout << a[i] << '\t';
    cout << endl; */

    for(int r = n - 1; r >= 0; r--){
        t = a[b + r];
        a[b + r] = a[b];
        a[b] = t;
        sift_down(a, b, b + r, b);
        /* for(int i = 0; i < n; i++) cout << a[i] << '\t';
        cout << endl; */
    } 
}
int main(){
    int n, res = 0, *a;
    cin >> n; a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    heap_sort(a, n, 0);

    /*  test for heap_sort()
    for(int j = 0; j < n; j++) cout << a[j] << '\t';
    cout << endl; */
    
    /* test for heap_sort()
    a[10] = a[10] + a[5] + a[11];
    for(int j = 10; j < n; j++) cout << a[j] << '\t';
    cout << endl;
    heap_sort(a, n, 10);
    for(int j = 10; j < n; j++) cout << a[j] << '\t';
    cout << endl; */



    for(int i = 1; i < n; i++){
        a[i] = a[i] + a[i - 1];
        res += a[i];
        heap_sort(a, n, i);
        /* // for debug
        for(int j = 0; j < n; j++) cout << a[j] << '\t';
        cout << "res: " << ' ' << res;
        cout << endl;  */
    } 
    res += a[n - 1];
    


    cout << res;
    // system("pause");
    return 0;
}
//log1 sort函数发生错误
//log2 代码结果错误，res结果太大
//log3 sort函数错误，逻辑错误
//log4 sift_down函数有问题
//log5 对sift_down算法优化
//log6 sift_down函数似乎没有问题
//log7 heap_sort函数检查出bug, 调用sift_down(a, b, r+b), expected sift_down(a, b, b+r, b);
//log8 res 没有初始化导致结果过大
#include<iostream>
using namespace std;
void sift_down(int* a, int k, int n){
    int j = k, i = 2 * j + 1, t;
    if(i < n - 1 && a[i + 1] < a[i]) i++;
    if(i < n && a[i] < a[j]){
        t = a[j];
        a[j] = a[i];
        a[i] = t;
        j = i;
    }
}
void heap_shift(int*a, int n){
    for(int i = (n - 1)/2; i >= 0; i--) sift_down(a, i, n);
}
int main(){
    int n, res = 0, *a;
    cin >> n; a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        heap_shift(&a[i - 1], n - i + 1); 
        heap_shift(&a[i], n - i);
        a[i] = a[i] + a[i - 1];
        res += a[i];
    } 
    res += a[n - 1]; 
    cout << res;
    //system("pause");
    return 0;
}
//log1 siftdown函数发生了越界访问
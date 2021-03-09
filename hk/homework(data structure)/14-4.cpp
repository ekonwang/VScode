#include<iostream>
#include<algorithm>
#define N 30
using namespace std;
void sift_down(int a[], int k, int n){   //elem stores from pos 1, as demanded.
    int i = k, j = 0;
    while( (j = 2 * i) <= n){
        if(j < n && a[j + 1] < a[j]) j++;// if right child is even smaller, choose the right one to cmp with parent
        if(a[i] > a[j]){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        i = j;
    }
}
void heap_adjust(int a[], int n){    //get a heap.
    for(int i = n/2; i >= 1; i--) sift_down(a, i, n);
}
void del_adjust(int a[], int k, int n){      //adjust function. 
    a[k] = a[n];
    sift_down(a, k, n - 1);
}
int main(){
    int a[N + 1];
    for(int i = 1; i <= N; i++) a[i] = rand();
    heap_adjust(a, N);
    for(int i = 1; i <= N; i++) cout << a[i] << " " ; cout << endl << endl;  //get a heap. 
    del_adjust(a, 10, N);
    for(int i = 1; i <= N - 1; i++) cout << a[i] << " " ; cout << endl;  //delete and adjust.
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;
void siftdown(int a[], int i, int n){
    int j;
    int t;
    t = a[i];
    while((j = 2 * i + 1) < n){
        if(j < n-1 && a[j] < a[j+1] )j++;
        if(t < a[j]){
            a[i] = a[j];
            i = j;
        }
    }
    a[j] = t;
}
void heap_sort(int a[], int n){
    int i;
    int t;
    for(i = (n - 2)/2; i >= 0; i--)siftdown(a, i, n);
    for(i = n - 1; i > 0; i--){
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        siftdown(a, 0, i);
    }
}
void sift_up(int a[], int k){
    int j = k, i = (j - 1)/2;
    int t = a[j];
    while(j > 0){
        if(a[i] >= t) break;
        else {a[j] = a[i]; j = i; i = (i - 1)/2;}
    }
    a[j] = t;
}
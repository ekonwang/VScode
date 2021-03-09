#ifndef heap_sort_h   //define ifndef 语句不区分大小写！
#define heap_sort_h
#include<iostream>
using namespace std;
void sift_down(int a[], int k, int n){   //最大堆调整
    int j = k, i = 2 * j + 1, t;
    while((i = 2 * j + 1) < n){
        if(i < n - 1 && a[i + 1] > a[i]) i++;
        if(a[i] > a[j]){
            t = a[j];
            a[j] = a[i];
            a[i] = t;
            j = i;
        }else break;
    }
}
void heap_sort(int a[], int n){
    int t;
    for(int i = (n - 1)/2; i >= 0; i--) sift_down(a, i, n);
    for(int i = n - 1; i >= 0; i--){
        t = a[i];
        a[i] = a[0];
        a[0] = t;
        sift_down(a, 0, i);
    }
}

#endif
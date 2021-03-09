#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
/* 最佳情况下插入排序的算法表现更好，在一般情况下三者的时间复杂度都是O(n2) */
/* 我个人认为插入排序是简单排序中最优良的算法 */
/* 事实上很多的高级排序算法都是以插入排序为基础建立的 */
template <class Item>
void InsertionSort(Item a[], int l, int r){
    int i, j; Item t;
    for(i = l + 1; i <= r; ++i){
        for(j = i - 1, t = a[i]; j >= l && a[j] > a[j + 1]; j--)
            a[j+1] = a[j];
        a[j + 1] = t;
    }
}
template <class Item>
void BubbleSort(Item a[], int l, int r){
    for(int i=1; i<r; ++i)
        for(int j=i; j < r; ++j)
            if(a[j + 1] < a[j])
                swap(a[j+1], a[j]);
    
}
template <class Item>
void SelectionSort(Item a[], int l, int r){
    int i, j, min;
    for(i=l; i<r; ++i){
        for(min=i, j=i; j<r; ++j)
            if(a[j] < a[min]) min=j;
        swap(a[min], a[i]);
    }
}
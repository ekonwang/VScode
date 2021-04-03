#include "BubbleSort.h"

void BubbleSort(int a[], int n){
    /* 
    * bubble sort, estimated complexity at O(n2)
    */
    if(n <= 1) return;
    for(int i = 0; i < n-1; ++i) 
        for(int j = n-1; j > i; --j) 
            if (a[j] < a[j-1]) {
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
}
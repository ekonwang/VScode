#include <iostream>
#include <ctime>
/* 
* 
* test program.
* writer : floyd wang.
* 
*/

using namespace std;
const int N = 50000;

void quick_sort(int a[], int left, int right){
    /* 
    * quick sort, estimated complexity at O(nlogn)
    */
    if(left >= right) return ;
    int l = left-1, r = right, k = a[right];
    while(l <= r) {
        while(a[++l] < k) {}
        while(r > left && a[--r] >= k) {}
        if(l >= r) break;
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
    }
    a[right] = a[l];
    a[l] = k;
    quick_sort(a, left, l-1);
    quick_sort(a, l+1, right);
}

void bubble_sort(int a[], int left, int right){
    /* 
    * bubble sort, estimated complexity at O(n2)
    */
    if(right <= left) return;
    for(int i = left; i <= right; ++i) 
        for(int j = right - 1; j >= i; --j) 
            if (a[j+1] < a[j]) {
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
}

int main() {
    /* 
    *   
    * main function.
    *  
    */
    clock_t startT, endT;
    srand(time(0));

    int a[N] = {0};
    for(int i = 0; i < N; i++) a[i] = rand();

    startT = clock();
    //bubble_sort(a, 0, N-1);
    quick_sort(a, 0, N-1);
    endT = clock();
    cout << "Data size : " << N << endl;
    cout << "Run time is : " << (double)(endT - startT) / CLOCKS_PER_SEC << endl;

    for(int j = 1; j < N; j++) if(a[j-1] > a[j]) cout << "No sorted" << endl;

    return 0;
}
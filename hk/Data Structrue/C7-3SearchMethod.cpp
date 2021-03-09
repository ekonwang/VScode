#include <iostream>
using namespace std;
template <class ElementType>
int search(ElementType n, ElementType a[], int lengh){
    int i;
    int low = 0;
    int high = length - 1;
    while(low <= high){
        tmp = (low + high)/2;
        if(n == a[tmp])
            return tmp;
        if(n > a[tmp])
            low = tmp + 1;
        else
            high = tmp - 1;
    }
    return -1;
}
template<class ElementType>
int seachB(ElementType n, ElementType a[], int length){
    int tmp;
    int low = 0;
    int high = length - 1;
    while(low <= high){
        tmp = (n - a[low])/(a[high] - a[low]) * (high - low) + low;
        if(n == getvalue(tmp))
            return tmp;
        if(n > a[tmp]) low = temp + 1;
        else high = tmp - 1;
    }
    return -1;
}
int reFib(int n);
int Fib(int n);
template <class ElementType>
int searchC(ElementType n, ElementType a[], int length){
    int i;
    int low = 0;
    int high = length - 1;
    int tmp;
    while(low <= high){
        i = reFib(high - low);
        tmp = Fib(i - 1) + low;
        if(a[tmp] == n)
            low = tmp + 1;
        else high = tmp - 1;
    }
    return -1;
}
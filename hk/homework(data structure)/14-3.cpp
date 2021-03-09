#include<iostream>
#include<algorithm>
#include<stack>
#include<windows.h>
#define N 400000
using namespace std;
struct pr{
    int head, tail;
    pr(int valA, int valB){
        head = valA; tail = valB;
    }
};
void QuickSort(int a[], int left, int right){
    if(right <= left) return;
    stack<pr> s;
    pr p(left, right);
    s.push(p);
    while(!s.empty()){
        int i, j, t;

        p = s.top(); 
        i = p.head - 1; j = p.tail, t = a[j];
        s.pop();
        while(true){
            while(a[++i] < t);
            while(a[--j] > t) if(j <= left) break;
            if(j <= i) break;
            swap(a[i], a[j]);
        }
        swap(a[i], a[p.tail]);
        if(i - 1 > p.head) {
            pr p1(p.head, i - 1);
            s.push(p1);
        }if(p.tail > i + 1){
            pr p2(i + 1, p.tail);
            s.push(p2);
        }
    }
}

int main(){
    int a[N];
    float res;
    for(int i = 0; i < N; i++){
        a[i] = rand();
    }
    DWORD64 s_time = GetTickCount();
    QuickSort(a, 0, N - 1);
    DWORD64 e_time = GetTickCount();
    res = (float) (e_time - s_time)/1000;
    cout << res << " s." << endl;
    system("pause");
    return 0;
}
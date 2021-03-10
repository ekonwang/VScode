#include <bits/stdc++.h>
using namespace std;
#define N 4
typedef long long LL;

double Sqrt(LL ar){
    double r = ar, l = 0, p = 1e-9, mid, dl;
    mid = (r + l)/2;
    dl = mid * mid;
    while(fabs(dl - ar) > p){
        if(dl > ar) r = mid;
        else l = mid;
        mid = (r + l)/2;
        dl = mid * mid;
    }
    return mid;
}
int main(){
    LL r = 100000000000000023;
    cout << setprecision(20) << sqrt(r) << endl;
    // int a[N] = {52, 34, 13, 2};
    // for(int i = 0; i < N; i++) r += sqrt(a[i]);
    // cout << r << endl;
    return 0;
}
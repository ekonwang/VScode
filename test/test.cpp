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
    LL t = 2;
    LL tp = 0x7fffffffffffffff;
    cout << tp << endl;
    return 0;
}
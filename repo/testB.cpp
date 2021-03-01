#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 1000010;
LL u, v, a[N], t, n, f = 0, ns = 0;

il void solve() {
    cin >> t;
    while(t--){
        f = ns = 0;
        cin >> n >> u >> v;
        For(i, 1, n) cin >> a[i];
        For(i, 1, n-1) { if(abs(a[i+1] - a[i]) > 1) f = 1; if(a[i+1] != a[i]) ns = 1;}
        if(f) cout << 0 << endl;
        else if(u < v){
            if(ns) cout << u << endl;
            else cout << u + v << endl;
        }else{
            if(ns) cout << v << endl;
            else cout << v + v << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
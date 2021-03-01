#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 100010;
int n, q, a[N], sum = 0, j, k;

il void solve() {
    cin >> n >> q;
    For(i, 1, n) {cin >> a[i]; sum += a[i];}
    while(q--){
        cin >> j >> k;
        if(j == 1){
            if(a[k] == 0) {a[k] = 1; sum ++;}
            else {a[k] = 0; sum --;}
        }else{
            if(k <= sum) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
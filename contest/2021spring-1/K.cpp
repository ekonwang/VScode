#include <bits/stdc++.h>
using namespace std;

#define il inline
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)
#define MAXLL 0x7fffffffffffffff
#define MAXINT 0x7fffffff

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 100000 + 5;
LL n, a[N], b[N], c[N];

il void solve() {
    cin >> n;
    LL res = MAXINT;

    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n > 60) {
        cout << 1 << endl;
        return;
    }
    for(LL l = 1; l < n; l ++) {
        for(LL r = l+2; r <= n; r++) {
            LL vl = 0, vr = a[r];
            for(LL t = l; t < r; t++) {
                vl ^= a[t];
            }
            for(int m = r-1; m >= l; m --) {
                if(vl > vr) {
                    res = min(r-l-1, res);
                    break;
                }
                vl ^= a[m];
                vr ^= a[m];
            }
        }
    }
    if(res == MAXINT) {
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
// n == 2;
// n > 60 res = 1; why bug ? 
// first you realize there is a constraint to, so brute force is OK for n <= 60.
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
LL n, k1, k2, t, w, b;

il void solve() {
    cin >> t;
    while(t--){
        cin >> n >> k1 >> k2 >> w >> b;
        if(min(k1, k2) + (max(k2, k1) - min(k2, k1))/2 < w ) {
            cout << "NO" << endl;
            continue;
        }else if(min(n-k1, n-k2) + (max(n-k1, n-k2) - min(n-k2, n-k1))/2 < b) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
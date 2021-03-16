#include <bits/stdc++.h>
using namespace std;

#define il inline
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 200000 + 5;
LL a[N], n, t, v, f;

il void solve() {
    cin >> t;
    while (t--) {
        f = 0;
        cin >> n;
        LL tp = n << 1;
        for (int i = 1; i <= tp; i++) {  //bug1
            cin >> a[i];
        }
        sort(a + 1, a + tp + 1);
        for (int i = 1; i < tp; i += 2) {
            if (a[i] != a[i + 1]) { f = 1; break; }
        }
        if (f) { cout << "NO" << endl; continue; }
        if (a[tp] % tp) { cout << "NO" << endl; continue; }
        LL dn = a[tp] / tp;
        for (int i = tp - 2; i >= 2; i -= 2) {
            LL tmp = i * dn - a[i + 2] + a[i];
            if (tmp % i || a[i+2] == a[i]) { f = 1; break; }
            LL dc = tmp / i;
            if (dc <= 0) { f = 1; break; }
            dn = dc;
        }
        if (f) { cout << "NO" << endl; continue; }

        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

//小bug
//没有充分理解题意
//没有注意是否产生溢出
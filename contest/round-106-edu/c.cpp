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
LL t, n, a[N], res[N], m[N], s[N], output;

il void solve() {
    cin >> t;
    while(t--){
        output = MAXLL;
        cin >> n;
        cin >> a[1] >> a[2];
        m[1] = 1;
        m[2] = 2;
        s[2] = a[1] + a[2];
        FOR(i, 3, n) {
            cin >> a[i];
            if(a[i] < a[m[i-2]]) m[i] = i;
            else m[i] = m[i-2];
            s[i] = a[i] + s[i-1];
        }
        FOR(i, 2, n) {
            if(i % 2) {
                LL tp = i / 2;
                res[i] = s[i] + (n - tp - 1) * a[m[i]] + (n - tp) * a[m[i-1]];
            }
            else {
                LL tp = i / 2;
                res[i] = s[i] + (n - tp) * a[m[i]] + (n - tp) * a[m[i-1]];
            }
        }
        FOR(i, 2, n) {
            output = min(output, res[i]);
        }
        cout << output << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
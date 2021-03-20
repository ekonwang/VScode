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
LL a[N], r[N], n, m, f[N];

LL assign(LL p, LL v) {
    r[p] = v + p > n ? 1 : a[v+p] + 1;
}

LL dfs(LL p) {
    if(f[p] != p && f[p] + a[f[p]] < n) return (f[p] = dfs(f[p]));
    else return f[p];
}

LL query(LL p) {
    cout << r[p] << ' ' << dfs(p);
}

LL solve(){
    cin >> n >> m;
    FOR(i, 1, n) {cin >> a[i];}
    REP(i, n, 1) {
        if(i + a[i] > n) { r[i] = 1; f[i] = i; }
        else {r[i] = r[i + a[i]]; f[i] = i + a[i]; }
    }
    FOR(i, 1, m) {
        LL instr, p, v;
        cin >> instr;
        if(!instr) {
            cin >> p >> v;
            a[p] = v;
            assign(p, v);
        }
        else {
            cin >> p;
            query(p);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
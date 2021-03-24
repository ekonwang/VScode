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
int a[N], r[N], n, m, f[N], lazy[N];

il void assign(int p, int v) {
    // r[p] = v + p > n ? 1 : r[p+v] + 1;
    // int af = v + p > n ? p : dfs(v+p); 
    // int tf = dfs(p);
    // REP(i, p-1, 1) {
    //     if(dfs(i) == tf) { f[i] = af; r[i] = r[i + a[i]] + 1; }
    // }
    // f[p] = af;
    a[p] = v;
    int tp = v + p > n? 1 : r[p+v] + 1;
    f[p] = p + v > n? p : p + v;
    lazy[p] = tp - r[p];
}

LL dfs(LL p) {
    int fa = f[p];
    if(fa != p) {
        int res = dfs(fa);
        if(lazy[fa]){
            r[fa] += lazy[fa];
            lazy[p] += lazy[fa];
            lazy[fa] = 0;
        }
        return res;
    }
    else return p;
}

il void query(LL p) {
    int fa = dfs(p);
    cout << dfs(p) << ' ' << r[p] + lazy[p] << endl;
}

il void solve(){
    memset(lazy, 0, sizeof(lazy));
    cin >> n >> m;
    FOR(i, 1, n) {cin >> a[i];}
    REP(i, n, 1) {
        if(i + a[i] > n) { r[i] = 1; f[i] = i; }
        else {r[i] = r[i + a[i]] + 1; f[i] = i + a[i]; }
    }
    FOR(i, 1, m) {
        LL instr, p, v;
        cin >> instr;
        if(!instr) {
            cin >> p >> v;
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
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

const int N = 200000 + 1000;
LL a[N], b[2*N], lazy[2*N], n, q;


void build(int s, int t, int p) {
    if(s == t) { b[p] = a[s]; return; }

    int m = (s + t) >> 1;
    build(s, m, p << 1);
    build(m+1, t, (p << 1) + 1);
    b[p] = min(b[p << 1], b[(p << 1) + 1]);
}

LL query(int l, int r, int s, int t, int p){
    if(l <= s && r >= t) return b[p];
    if(r < s || l > t) return MAXLL;

    int m = (s + t) >> 1;
    if(lazy[p]) {
        lazy[p << 1] += lazy[p];
        lazy[(p << 1) + 1] += lazy[p];
        lazy[p] = 0;
    }
    LL ansL = query(l, r, s, m, p << 1);
    LL ansR = query(l, r, m+1, t, (p << 1) + 1);
    return min(ansL, ansR);
}

void update(int l, int r, int c, int s, int t, int p) {
    if(l <= s && r >= t) {b[p] += c; lazy[p] += c; return; }
    if(r < s || l > t) return;

    int m = (s + t) >> 1;
    if(lazy[p]) {
        b[p << 1] += lazy[p];
        lazy[p << 1] += lazy[p];
        b[(p << 1) + 1] += lazy[p];
        lazy[(p << 1) + 1] += lazy[p];
        lazy[p] = 0;
    }
    update(l, r, c, s, m, p << 1);
    update(l, r, c, m+1, t, (p << 1) + 1);
    b[p] = min(b[p << 1], b[(p << 1) + 1]);
}
//更新这步没做完


int main() {
    ios::sync_with_stdio(0);
    int i1, i2, i3;

    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    build(1, n, 1);
    cin >> q;
    while(q--){
        cin >> i1 >> i2;
        i1++; i2++;
        if(cin.get() == '\n') {
            if(i1 <= i2) {
                cout << query(i1, i2, 1, n, 1) << endl;;
            }
            else {
                cout << min( query(1, i2, 1, n, 1), query(i1, n, 1, n, 1) ) << endl;
            }
        }
        else {
            cin >> i3;
            if(i1 <= i2) {
                update(i1, i2, i3, 1, n, 1);
            }
            else {
                update(1, i2, i3, 1, n, 1);
                update(i1, n, i3, 1, n, 1);
            }
        }
    }
    return 0;
}
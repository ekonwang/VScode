#include <bits/stdc++.h>
using namespace std;

#define il inline
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

LL const MAXLL = 0x7fffffffffffffffLL;
LL const MAXINT = 0x7fffffff;

const int N = 200000 + 1000;
LL b[N << 2], lazy[N << 2], n, q;


void build(int s, int t, int p) {
    if(s == t) { cin >> b[p]; return; }

    int m = (s + t) >> 1;
    build(s, m, p << 1);
    build(m+1, t, (p << 1) + 1);
    b[p] = min(b[p << 1], b[(p << 1)|1]);
}

LL query(int l, int r, int s, int t, int p){
    if(l <= s && r >= t) return b[p];

    int m = (s + t) >> 1;
    if(lazy[p]) {
        lazy[p << 1] += lazy[p];
        //bug
        b[p << 1] += lazy[p];
        lazy[(p << 1)|1] += lazy[p];
        b[p << 1|1] += lazy[p];
        lazy[p] = 0;
    }
    LL ansL = l <= m ? query(l, r, s, m, p << 1): MAXLL;
    LL ansR = r > m ? query(l, r, m+1, t, (p << 1) + 1): MAXLL;
    return min(ansL, ansR);
}

void update(int l, int r, int c, int s, int t, int p) {
    if(l <= s && r >= t) {b[p] += c; lazy[p] += c; return; }
    //if(r < s || l > t) return;      
    int m = (s + t) >> 1;
    if(lazy[p]) {
        b[p << 1] += lazy[p];
        lazy[p << 1] += lazy[p];
        b[(p << 1)|1] += lazy[p];
        lazy[(p << 1)|1] += lazy[p];
        lazy[p] = 0;
    }
    //update(l, r, c, s, m, p << 1);
    //update(l, r, c, m+1, t, (p << 1) + 1);
    if(l <= m) update(l, r, c, s, m, p << 1);
    if(r > m) update(l, r, c, m+1, t, p << 1|1);
    b[p] = min(b[p << 1], b[(p << 1)|1]);
}


int main() {
    ios::sync_with_stdio(0);
    int i1, i2, i3;

    cin >> n;
    build(1, n, 1);
    cin >> q;
    while(q--){
        cin >> i1 >> i2;
        i1++; i2++;
        if(cin.get() == ' ') {
            cin >> i3;
            if(i1 <= i2) {
                update(i1, i2, i3, 1, n, 1);
            }
            else {
                update(1, i2, i3, 1, n, 1);
                update(i1, n, i3, 1, n, 1);
            }
        }
        else {
            if(i1 <= i2) {
                cout << query(i1, i2, 1, n, 1) << endl;;
            }
            else {
                cout << min( query(1, i2, 1, n, 1), query(i1, n, 1, n, 1) ) << endl;
            }
        }
    }
    return 0;
}
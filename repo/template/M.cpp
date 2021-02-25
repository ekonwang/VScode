#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define rep(i,n) for(int i = 0, (i##i) = (n); i<(i##i); ++i)
#define Fodn(i,a,b) for(int i = (a), (i##i) = (b); i>=(i##i); --i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

template<typename T>
il bool read(T& x) {
    x = 0; char c = getchar(); int f = 1;
    while ((c < '0' || c>'9') && (c != '-') && (c != EOF))c = getchar();
    if (c == EOF)return 0; if (c == '-') f = -1, c = getchar();
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    x *= f; return 1;
}
template<typename T, typename...Args>
il bool read(T& x, Args&...args) { bool res = 1; res &= read(x); res &= read(args...); return res; }

const double EPS = 1e-6;
const int M = 1000000007, INF = 0x3f3f3f3f;
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1000010;

int n, k, a[8];

il bool init() {
    read(k); if (k == 0)return 0;
    memset(a, 0, sizeof a);
    n = 0;
    For(i, 1, k) read(a[i]), n += a[i];
    return 1;
}

il void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
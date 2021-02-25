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
const int N = 2010;

LL n, a[N], s[N], s2[N], dp[N][N] = {0}, dp2[N][N] = {0};

bool cmp(int a, int b) {
    return a > b;
}

il void solve() {
    LL len = 0, len2 = 0, res = 1e18;
    cin >> n;
    For(i,1,n) { cin >> a[i]; s2[i] = s[i] = a[i];}
    sort(s+1, s+n+1);
    sort(s+1, s+n+1, cmp);
    len = unique(s+1, s+n+1) - s - 1;
    len2 = unique(s2+1, s2+n+1) - s2 - 1;
    For(i, 1, n){
        LL minv = 1e18;
        For(j, 1, len){
            // 引理，可以用a[]中的数值构造出满足题意的数列
            // 这道题的转移方程实际上很简单：dp[i][j] = min{dp[i-1][k]} + abs(a[i] - s[j])  (k <= j) 
            minv = min(dp[i-1][j], minv);
            dp[i][j] = minv + abs(s[j]- a[i]);
        }
    }
    For(i, 1, n){
        LL minv = 1e18;
        For(j, 1, len2){
            minv = min(dp2[i-1][j], minv);
            dp2[i][j] = minv + abs(s[j]- a[i]);  //dp 转移过程是完全一样的
        }
    }
    For(i, 1, len) res = min(res, dp[n][i]);
    For(i, 1, len2) res = min(res, dp2[n][i]);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
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
const int N = 3010;

int n, res = 0, a[N] = {0}, b[N] = {0}, dp[N][N] = {0};

il void solve() {
    int n;
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i]; 
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        // for(int j = 1; j <= n; j++){
        //     if(a[i] > b[j-1]) tmp = max(tmp, dp[i-1][j-1]);
        //     if(a[i] == b[j]) dp[i][j] = tmp + 1;
        //     else dp[i][j] = dp[i-1][j];
        // }
        for(int j = 1; j <= n; j++){
            dp[i][j] = a[i] == b[j] ? tmp + 1: dp[i-1][j];
            tmp = a[i] > b[j] ? max(dp[i-1][j], tmp) : tmp;
            //稍微调整一下tmp更新的顺序就可以达到理想的效果
        }
    }
    for(int i = 1; i <= n; i++) res = max(res, dp[n][i]);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
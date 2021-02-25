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
const int INF = 0x3f3f3f3f;
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int N = 51, M = 51;

LL n, m, a[N][M], dp[N+M][N][N] = {0};

il bool init() {
    cin >> n >> m;
    For(i, 1, n)For(j, 1, m) cin >> a[i][j];
}

il void solve() {
    For(l, 1, n + m - 2)For(i, 1, n)For(j, 1, n){
        LL yi = l + 2 - i, yj = l + 2 - j;
        if(i == j){
            if(l+1-i > 0)
            dp[l][i][j] = max(dp[l][i][j], dp[l-1][i][j] + a[i][yi]);
            if(i-1 > 0)
            dp[l][i][j] = max(dp[l][i][j], dp[l-1][i-1][j-1] + a[i][yi]);
            if(i-1 > 0 && l+1-i > 0){
                dp[l][i][j] = max(dp[l][i][j], dp[l-1][i-1][j] + a[i][yi]);
                dp[l][i][j] = max(dp[l][i][j], dp[l-1][i][j-1] + a[i][yi]);
            }
        }
        else{
            if(l+1-i > 0 && l+1-j)
            dp[l][i][j] = max(dp[l][i][j], dp[l-1][i][j] + a[i][yi] + a[j][yj]);
            if(i-1 > 0 && j-1 > 0)
            dp[l][i][j] = max(dp[l][i][j], dp[l-1][i-1][j-1] + a[i][yi] + a[j][yj]);
            if(i-1 > 0 && l+1-j > 0)
            dp[l][i][j] = max(dp[l][i][j], dp[l-1][i-1][j] + a[i][yi] + a[j][yj]);
            if(j-1 > 0 && l+1-1 > 0)
            dp[l][i][j] = max(dp[l][i][j], dp[l-1][i][j-1] + a[i][yi] + a[j][yj]);
        }
    }
    cout << dp[n+m-2][n][n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
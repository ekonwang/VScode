#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define pln puts("")
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
    LL***** dp = new LL * ***[a[1] + 1];
    For(i, 0, a[1]) {
        dp[i] = new LL * **[a[2] + 1];
        For(j, 0, a[2]) {
            dp[i][j] = new LL * *[a[3] + 1];
            For(k, 0, a[3]) {
                dp[i][j][k] = new LL * [a[4] + 1];
                For(l, 0, a[4]) {
                    dp[i][j][k][l] = new LL[a[5] + 1];
                    For(m, 0, a[5])
                        dp[i][j][k][l][m] = 0;
                }
            }
        }
    }

    dp[0][0][0][0][0] = 1;
    For(i, 0, a[1])For(j, 0, a[2])For(k, 0, a[3])For(l, 0, a[4])For(m, 0, a[5]) {
        if (i < a[1]) dp[i + 1][j][k][l][m] += dp[i][j][k][l][m];
        if (j < a[2] && j < i) dp[i][j + 1][k][l][m] += dp[i][j][k][l][m];
        if (k < a[3] && k < j) dp[i][j][k + 1][l][m] += dp[i][j][k][l][m];
        if (l < a[4] && l < k) dp[i][j][k][l + 1][m] += dp[i][j][k][l][m];
        if (m < a[5] && m < l) dp[i][j][k][l][m + 1] += dp[i][j][k][l][m];
    }
    cout << dp[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;

    For(i, 0, a[1]) {
        For(j, 0, a[2]) {
            For(k, 0, a[3]) {
                For(l, 0, a[4])
                    delete[]dp[i][j][k][l];
                delete[]dp[i][j][k];
            }
            delete[]dp[i][j];
        }
        delete[]dp[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    while (init())solve();
    return 0;
}
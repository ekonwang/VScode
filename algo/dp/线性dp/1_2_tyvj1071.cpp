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
const int N = 5004;

LL r = 0, n, a[N], b[N], dp[N][N];

il bool init() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    return true;
}

//说实话还是不太会写，转移代码无从下手
//if(i == j) dp[i][j] = max{dp[i'][j']} + 1
il void solve() {
    init();
    memset(dp, 0, sizeof dp);
    For(i ,1 ,n){
        LL val = 0;
        For(j, 1, n){
            if(a[i] == b[j]) dp[i][j] = val + 1;
            else dp[i][j] = dp[i-1][j];
            if(b[j] < a[i]) val = max(val, dp[i-1][j]);                 //val 是一个优化绝佳的优化，直接将算法复杂度从O(n3) 降低至 O(n2)
            r = max(r, dp[i][j]);
        }
    }
    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
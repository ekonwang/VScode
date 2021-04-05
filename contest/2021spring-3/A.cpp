#include <bits/stdc++.h>                                                     //*
#define il inline                                                            //*
#define ll long long                                                         //*
#define INT __int64                                                          //*
#define usn unsigned                                                         //*
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
ll const MAXLL = 0x7fffffffffffffffLL;                                       //*
int const MAXINT = 0x7fffffff;                                               //*
const int INF = 0x3f3f3f3f;                                                  //*
const ll INF_LL = 9223372036854775807LL;                                     //*
const double E = exp(1.0);                                                   //*
const double PI = acos(-1.0);                                                //*
ll gcd(ll a, ll b) { while (b ^= a ^= b ^= a %= b); return a; }              //*
ll lcd(ll a, ll b) { return a * b / gcd(a, b); }                             //*
inline ll read() {                                                           //*
    char ch = getchar(); ll x = 0, f = 1;                                    //*
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }  //*
    while ('0' <= ch && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar();} //*
    return x * f;                                                            //*
}                                                                            //*
inline void write(ll x)                                                      //*
{                                                                            //*
    if (x < 0) {                                                             //*
        putchar('-');                                                        //*
        x = -x;                                                              //*
    }                                                                        //*
    if (x > 9) write(x / 10);                                                //*
    putchar(x % 10 + '0');                                                   //*
}                                                                            //*
void init_cin() {                                                            //*
    std::ios::sync_with_stdio(false);                                        //*
    std::cin.tie(nullptr);                                                   //*
    std::cout.tie(nullptr);                                                  //*
}                                                                            //*
using namespace std;                                                         //*
//---------------------------------------------------------------------------//*

// debug思路:
// 算法是否正确 -> 程序是否严格按照我算法的思路严格执行 -> 找到一组错误数据使用单步调试找到问题所在 
// 算法写得清晰不容易出错很重要，不要把程序写得乱七八糟


const int N = 200000 + 5;
int n, h, a[N], b[N], s[N], c[N], dp[N];
// O(n)算法 贪心

void solve() {
    ll ans = 0, tp = 0, d = 1, i, j;
    cin >> n >> h;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(s ,0, sizeof(s));
    memset(c, 0, sizeof(c));
    memset(dp, 0, sizeof(dp));

    FOR(i, 1, n) cin >> a[i] >> b[i];
    FOR(i, 1, n) {
        c[i] = c[i-1];
        s[i] = s[i-1];
        s[i] += (b[i] - a[i]);
        c[i] += (a[i+1] - b[i]);
    }
    c[n] = MAXINT;

    // drop = 掉落在第几个b区间
    tp = h;
    for(i = 1; i <= n; i++) {
        for(j = d; j <= n; j++) {
            int tmp = c[i-1];
            if(c[j-1] - tmp < tp && tp <= c[j] - tmp) { 
                d = j;
                dp[i] = s[d] - s[i-1];
                break;
            }
        }
        if(d == n) break;
    }
    int res = 0;
    FOR(k, 1, i) {
        res = max(res, dp[k]);
    }
    cout << res + h << endl;
}

// int r = h, drop = 0, ad;
// while (r > 0) {
//     drop++;
//     r -= b[drop];
//     tp += (a[drop] + b[drop - 1]);
//     if (drop >= n) break;
// }
// if (drop >= n) { cout << tp + r << endl; return; }

// ad = (r + b[drop]);
// ans = max(ans, tp + ad);
// FOR(i, 1, n - 1) {
//     r += b[i];
//     tp -= (b[i] + a[i]);
//     while (r > 0) {
//         drop++;
//         r -= b[drop];
//         tp += (a[drop] + b[drop - 1]);
//         if (drop >= n) break;
//     }
//     if (drop >= n) { cout << tp + r << endl; return; }
//     ad = (r + b[drop]);
//     ans = max(ans, tp + ad);
// }
// cout << ans << endl;

int main() {
    init_cin();
    solve();
    return 0;
}
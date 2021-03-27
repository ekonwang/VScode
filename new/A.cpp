#include <bits/stdc++.h>                                                     //*
#define il inline                                                            //*
#define ll long long                                                         //*
#define INT __int64                                                          //*
#define usn unsigned                                                         //*
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
#define MAXLL 0x7fffffffffffffff                                             //*
#define MAXINT 0x7fffffff                                                    //*
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



const int N = 200000 + 5;
int n, h, a[N], b[N], x1, x2;
// O(n)算法 贪心

void solve() {
    ll ans = 0, tp = 0;
    cin >> n >> h;
    x1 = x2 = 0;
    FOR(i, 1, n) {
        cin >> x1;
        b[i - 1] = x1 - x2;
        cin >> x2;
        a[i] = x2 - x1;
    }
    b[n] = b[0] = 0;

    int r = h, drop = 0, ad;
    while (r > 0) {
        drop++;
        r -= b[drop];
        tp += (a[drop] + b[drop - 1]);
        if (drop >= n) break;
    }
    if (drop >= n) { cout << tp + r << endl; return; }
    
    ad = (r + b[drop]);
    ans = max(ans, tp + ad);
    FOR(i, 1, n - 1) {
        r += b[i];
        tp -= (b[i] + a[i]);
        while (r > 0) {
            drop++;
            r -= b[drop];
            tp += (a[drop] + b[drop - 1]);
            if (drop >= n) break;
        }
        if (drop >= n) { cout << tp + r << endl; return; }
        ad = (r + b[drop]);
        ans = max(ans, tp + ad);
    }
    cout << ans << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
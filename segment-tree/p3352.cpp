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
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}                            //*
ll lcd(ll a , ll b){return a * b / gcd(a,b);}                                //*
inline ll read(){                                                            //*
    char ch = getchar(); ll x = 0, f = 1;                                    //*
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}      //*
    while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}   //*
    return x * f;                                                            //*
}                                                                            //*
inline void write(ll x)                                                      //*
{                                                                            //*
    if(x<0) {                                                                //*
        putchar('-');                                                        //*
        x = -x;                                                              //*
    }                                                                        //*
    if(x>9) write(x / 10);                                                   //*
    putchar(x % 10 + '0');                                                   //*
}                                                                            //*
void init_cin(){                                                             //*
  std::ios::sync_with_stdio(false);                                          //*
  std::cin.tie(nullptr);                                                     //*
  std::cout.tie(nullptr);                                                    //*
}                                                                            //*
using namespace std;                                                         //*
//---------------------------------------------------------------------------//*

/* 就是一道brute force 的题目，但是要很多技巧 */
/* 不对，不是brute force, 似乎需要利用dp，所以这道题实际上更是一道dp题，并且是多维dp问题 */


const int N = 401;

/* int a[N], po[N][N], Map[N], n, m, q, sted[N];

void solve() {
    int max = 0;
    memset(po, 0, sizeof(po));
    cin >> n >> q;

    /* distinct */
    /* FOR(i,1,n) {cin >> a[i]; sted[i] = a[i];}
    m = unique(sted, sted+n) - sted;
    sort(sted, sted + m);

    FOR(i, 1, n) { int v = a[i]; FOR(j, 1, m) if(v == sted[j]) Map[i] = j; }

    for(int l = 1; l <= n; l++) {
        int max = -1, loc = 0;
        for(int r = l; r <= n; r++) {
            if(a[r] > max) max = a[r], loc = r;
            for(int i = 1; i <= n; i++) {
                if(l <= i && i <= r) po[i][Map[loc]] ++;}}}
    

    

} */ 

void solve(){
    
}

int main() {
    init_cin();
    solve();
    return 0;
}
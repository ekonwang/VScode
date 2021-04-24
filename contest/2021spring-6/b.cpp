#include <bits/stdc++.h>                                                     //*
#define FOR(i,a,b) for(int (i) = (a); i <= (b); ++i)                         //*
#define REP(i,a,b) for(int (i) = (a); i >= (b); --i)                         //*
using namespace std;                                                         //*
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef struct{int lchild, rchild, index; } node;
const ll MAXLL = 0x7fffffffffffffffLL;                                       //*
const int MAXINT = 0x7fffffff;                                               //*
const int INF = 0x3f3f3f3f;                                                  //*
const double E = exp(1.0);                                                   //*
const double PI = acos(-1.0);                                                //*
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}                            //*
ll lcd(ll a , ll b){return a * b / gcd(a,b);}                                //*
ll phi(ll a) {                                                               //*
    ll tmp = a, ans = a, d = 2;                                              //*
    while(d * d <= tmp) {                                                    //*
        ll cnt = 0;                                                          //*
        while(tmp % d == 0) {tmp /= d; cnt ++;} if(cnt) ans -= ans / d; d++; //*
    }                                                                        //*
    if(tmp > 1) ans -= ans/tmp;                                              //*
    return ans;                                                              //*
}
void init_cin(){                                                             //*
std::ios::sync_with_stdio(false);                                            //*
std::cin.tie(nullptr);                                                       //*
std::cout.tie(nullptr);                                                      //*
}                                                                            //*
//---------------------------------------------------------------------------//*
// 双状态 、 匹配问题
const ll N = 2e5 + 5;
vll L, R, neg;
ll a[N], S[N], n, v, sum0, sum1;

void solve() {
    int len;
    ll res, lres;
    cin >> n;
    FOR(i, 1, n){
        cin >> v;
        if(v < 0) a[i] = 1;
    }
    S[0] = 0;
    FOR(i, 1, n){
        S[i] = S[i-1] ^ a[i];
    }
    FOR(i, 0, n){
        if(S[i]) sum1 ++;
        else sum0 ++;
    }
    lres = sum0 * sum1;
    res = 1ll*(n + 1)*n/2 - lres;
    cout << lres << ' ' << res << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
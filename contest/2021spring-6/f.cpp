#include <bits/stdc++.h>                                                     //*
#define FOR(i,a,b) for(int (i) = (a); i <= (b); ++i)                         //*
#define FORN(i,n) for(int (i) = (0); i < n; ++i)
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

const int N = 400000 + 5;
set<int> s;
multiset<int> ms;
vi v;
int n, I, K, K_, a[N], C;

int retK(int k){
    for(int i = 0; i <= 30; i++){
        if(k <= (1 << i))
            return i;
    }
    return -1;
}

void solve() {
    cin >> n >> I;
    FOR(i, 0, n-1){
        cin >> a[i];
        s.insert(a[i]);
        ms.insert(a[i]);
    }
    for(int elem: s){
        v.push_back(ms.count(elem));
    }
    C = s.size();
    int K = retK(C), sum = 0, res = 0;
    if(8*I >= n*K) {
        cout << 0 << endl;
        return;
    }
    K_ = 1 << (8*I/n);
    FORN(i, K_) sum += v[i];
    res = sum;
    FOR(i, K_, C-1) {
        sum -= v[i-K_];
        sum += v[i];
        res = max(sum, res);
    }
    cout << n - res << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
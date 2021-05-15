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

const int N = 100000 + 5;
int n, a[N], ca[N], b[30], st = 0;
bool cmp(int x, int y) {return x >= y;}
void add(int x){
    FOR(i, 0, 29){
        if((1 << i) & x) b[i]++;
    }
}
void solve() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        add(a[i]);
    }
    FOR(i, 0, 29){
        if(b[i] == 1) st ^= (1 << i);
    }
    FOR(i, 1, n){
        ca[i] = a[i] & st;
    }
    int ma = -1, mi = -1;
    FOR(i, 1, n){
        if(ca[i] > ma) { mi = i; ma = ca[i]; }
    }
    swap(a[1], a[mi]);
    FOR(i, 1, n) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
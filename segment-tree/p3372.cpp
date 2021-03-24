#include <bits/stdc++.h>                                                     //*
#define il inline                                                            //*
#define ll long long                                                         //*
#define INT __int64                                                          //*
#define usn unsigned                                                         //*
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
const ll  MAXLL = 0x7fffffffffffffffLL;                                      //*
const ll  MAXINT = 0x7fffffff;                                               //*
const double E = exp(1.0);                                                   //*
const double PI = acos(-1.0);                                                //*
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}                            //*
ll lcd(ll a , ll b){return a * b / gcd(a,b);}                                //*
void init_cin(){                                                             //*
  std::ios::sync_with_stdio(false);                                          //*
  std::cin.tie(nullptr);                                                     //*
  std::cout.tie(nullptr);                                                    //*
}                                                                            //*
using namespace std;                                                         //*
//---------------------------------------------------------------------------//*

/* 
bug 日志： update没有约束好递归导致无限递归, runtime error. */

const ll N = 100000 + 1000;
ll b[N << 2], lazy[N << 2];

void pushup(ll p) {
    b[p] = b[p << 1] + b[p << 1|1];
}

void pushdown(ll s, ll t, ll p) {
    if(ll tmp = lazy[p]) {
        ll m = (s + t) >> 1;
        lazy[p << 1] += tmp;
        b[p << 1] += (m - s + 1) * tmp;
        lazy[p << 1|1] += tmp;
        b[p << 1|1] += (t - m) * tmp;
        lazy[p] = 0; 
    }
}

void build(ll s, ll t, ll p) {
    if(s == t) { cin >> b[p]; return; }

    ll m = (s + t) >> 1;
    build(s, m, p << 1);
    build(m+1, t, (p << 1) + 1);
    pushup(p);
}

ll query(ll l, ll r, ll s, ll t, ll p){
    if(l <= s && r >= t) return b[p];

    int m = (s + t) >> 1;
    pushdown(s, t, p);
    ll res = 0;
    res += l <= m ? query(l, r, s, m, p << 1) : 0; 
    res += r > m ? query(l, r, m+1, t, (p << 1)|1) : 0 ;

    return res;
}

void update(ll l, ll r, ll c, ll s, ll t, ll p) {
    if(l <= s && r >= t) {b[p] += c * (t - s + 1); lazy[p] += c; return; }

    ll m = (s + t) >> 1;
    pushdown(s, t, p);
    if(l <= m) update(l, r, c, s, m, p << 1);
    if(r > m) update(l, r, c, m+1, t, p << 1|1);
    pushup(p);
}

void solve(){
    ll n, q, c, ins, l, r;
    cin >> n >> q;
    build(1, n, 1);
    while(q--) {
        cin >> ins >> l >> r;
        if(ins == 1) {
            cin >> c;
            update(l, r, c, 1, n, 1);
        }
        else if(ins == 2){
            cout << query(l, r, 1, n, 1) << endl;
        }
    }
}

int main() {
    init_cin();
    solve();
    return 0;
}
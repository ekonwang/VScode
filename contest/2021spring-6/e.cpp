/* codeforces */
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

const int N = 2e5 + 5;
int n, a[N << 2], lazy[N << 2], q;

void push_up(int p){
    a[p] = max(a[p << 1], a[p << 1|1]);
}

void build(int s, int t, int p) {
    if(s >= t){
        cin >> a[p];
        return;
    }
    int m = (s+t) >> 1;
    build(s, m, p << 1);
    build(m+1, t, p<<1|1);
    push_up(p);
}

void push_down(int s, int t, int p){
    if(lazy[p]) {
        int lp = lazy[p];
        a[p] = max(a[p], lp);
        lazy[p << 1] = max(lp, lazy[p << 1]);
        a[p << 1] = max(lp, a[p << 1]);
        lazy[p << 1|1] = max(lp, lazy[p << 1|1]);
        a[p << 1|1] = max(lp, a[p << 1|1]);
        lazy[p] = 0; //这一步有问题哦，需要更新这里
    }
}

void update2(int l, int r, int c, int s, int t, int p){
    if(s >= l && t <= r) {
        lazy[p] = max(lazy[p], c);
        a[p] = max(c, a[p]);
    }
}

void update(int l, int r, int c, int s, int t, int p){
    //cout << "s t " << s << ' ' << t <<  endl;
    if(s >= l && t <= r) {
        a[p] = c;
        return;
    }
    push_down(s, t, p);
    int m = (s + t) >> 1;
    if(l <= m) update(l, r, c, s, m, p << 1);
    if(r > m) update(l, r, c, m+1, r, p << 1|1);
    push_up(p);
}

int query(int l, int r, int s, int t, int p){
    if(l <= s && t <= r) {
        return a[p];
    }
    push_down(s, t, p);
    int m = (s + t) >> 1;
    if(l <= m) return query(l, r, s, m, p << 1);
    else return query(l, r, m+1, t, p << 1|1);
}

void solve(){
    int q, x, y, z;
    cin >> n;
    build(1, n, 1);
    cin >> q;
    while(q--){
        cin >> x;
        if(x == 1) {
            cin >> y >> z;
            update(y, y, z, 1, n, 1);
        }
        else {
            cin >> z;
            update2(1, n, z, 1, n, 1);
        }
    }
    FOR(i, 1, n) {
        cout << query(i, i, 1, n, 1) << ' ';
    }
}

int main() {
    init_cin();
    solve();
    return 0;
}
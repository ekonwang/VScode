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

const int N = 3e5 + 5, M = 2e3;
int n, a[N], ab[N], b[M], bz, q; 

void solve() {
    int x, y, z, bn;
    cin >> n;
    bz = sqrt(n);
    int bmx = n/bz, bmi = 1/bz;
    FOR(i, 1, n){
        cin >> a[i];
        ab[i] = i/bz;
    }
    cin >> q;
    while(q--){
        cin >> x;
        if(x == 1){
            int start, end;
            cin >> y >> z;
            bn = y/bz;
            start = bn * bz;
            end = bn * bz + bz - 1;
            FOR(i, start, end) {
                a[i] = max(a[i], b[bn]);
            }
            a[y]=z;
            b[bn] = 0;
        }else{
            cin >> z;
            FOR(i, bmi, bmx){
                b[i] = max(z, b[i]); 
            }
        }
    }
    FOR(i, 1, n){
        int tp = i/bz;
        cout << max(a[i], b[tp]) << ' ';
    }
}

int main() {
    init_cin();
    solve();
    return 0;
}
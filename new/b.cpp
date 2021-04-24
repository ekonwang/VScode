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

const ll N = 2e5 + 5;
vll L, R, neg;
ll a[N], n, v;

void solve() {
    int len;
    ll res, lres;
    cin >> n;
    FOR(i, 0, n-1){
        cin >> v;
        if(v < 0) neg.push_back(i);
    }
    len = neg.size();

    if(len == 0) {
        res = (n+1) * (n) / 2;
        cout << res << ' ' << 0 << endl;
    }
    else if(len == 1) {
        int pos = neg[0];
        res = (n - pos) * (pos + 1);
        lres = (n + 1)  * (n) / 2 - res;
        cout << lres << ' ' << res << endl;
    }else{
        L.push_back(0);
        R.push_back(neg[1]-1);
        FOR(i, 1, len-2){
            L.push_back(neg[i-1]+1);
            R.push_back(neg[i+1]-1);
        }
        L.push_back(neg[len-2]+1);
        R.push_back(n-1);
        for(int k = 0; k < len; k+=2) {
            for(int r = k; r < len; r++) {
            }
        }
    }
}

int main() {
    init_cin();
    solve();
    return 0;
}
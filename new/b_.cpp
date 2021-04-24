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
int a[N], v;
ll res, tres, n;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = rand();
        cout << a[i] << ' ';
    }cout << endl;
    clock_t b, e;
    b = clock();
    tres = (n+1) * n/2;
    FOR(i, 1, n){
        //cin >> v;
        if(a[i] < 0) a[i] = 1;
    } 
    FOR(i, 1, n) {
        int tmp = 0;
        FOR(j, i, n){
            tmp = tmp ^ a[j];  //很多时候就是低级错误， 太容易了， 计算机不可能出错的
            if(tmp) res ++;
        }
    }
    cout << res << ' ' << tres - res << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
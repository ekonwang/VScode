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
int n, s1, s2, d1, d2;
string s;

void solve() {
    cin >> n;
    cin >> s;
    FORN(i, n){
        if(i < n/2){
            if(s[i] == '?') d1++;
            else s1 += s[i] - '0';
            continue;
        }
        if(s[i] == '?') d2++;
        else s2 += s[i] - '0';
    }
    int tmp = 2 * (s1 - s2) + 9 * (d1 - d2);
    if(tmp) {
        cout << "Monocarp" << endl;
    }else{
        cout << "Bicarp" << endl;
    }
}

int main() {
    init_cin();
    solve();
    return 0;
}
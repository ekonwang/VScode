#include <bits/stdc++.h>                                                     //*
#define il inline                                                            //*
#define ll long long                                                         //*
#define INT __int64                                                          //*
#define usn unsigned                                                         //*
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
ll const MAXLL = 0x7fffffffffffffffLL;                                       //*
int const MAXINT = 0x7fffffff;                                               //*
const int INF = 0x3f3f3f3f;                                                  //*
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

int cmp(pair<int,int>a,pair<int,int>b){
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
//---------------------------------------------------------------------------//*



const int N = 100 + 5;
int n, a[N], test[N], tot[N], tot2[N], t, f;

bool same(int n, int first[], int second[]){
    FOR(i, 1, n) if(first[i] != second[i]) return false;
    return true;
}

void sum() {
    FOR(i, 1, n-1)
        tot2[i] = test[i] + test[i+1];
    sort(tot2 + 1, tot2 + n);
}

bool valid() {
    if(same(n, a, test)) return false;
    if(same(n-1, tot, tot2)) return true;
    return false;
}

void print() {
    FOR(i, 1, n) cout << test[i] << ' '; cout << endl;
}

void solve() {
    cin >> t;

    while(t --) {
        f = 0;
        cin >> n;

        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) test[i] = i;
        FOR(i, 1, n-1) tot[i] = a[i] + a[i+1];
        sort(tot + 1, tot + n);

        do {
            sum();
            if(valid()) { print(); break; }
        }while(next_permutation(test + 1, test + n + 1));

    }

}

int main() {
    init_cin();
    solve();
    return 0;
}
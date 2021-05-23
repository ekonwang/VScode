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

const int N = 100;
int a[N][N], t, r, c;
string s;

void solve() {
    cin >> t;
    while(t--){
        int edgeline = 0, line = 0, corner = 0, edge = 0, counts = 0, res = -1;
        cin >> r >> c;
        FORN(i, r){
            cin >> s;
            FORN(j, c){
                if(s[j] == 'A'){
                    a[i+1][j+1] = 1;
                }else{
                    a[i+1][j+1] = 0;
                }
            }
        }
        /* line in r */
        FOR(i, 1, r){
            int tp = 0;
            FOR(j, 1, c){
                tp += a[i][j];
                counts += a[i][j];
            }
            if(tp == c){
                if(i == 1 || i == r){
                    edgeline = 1;
                }
                line = 1;
            }
            if(tp && (i == 1 || i == r))
                edge = 1;
        }
        /* line in c */
        FOR(j, 1, c){
            int tp = 0;
            FOR(i, 1, r){
                tp += a[i][j];
            }
            if(tp == r){
                if(j == 1 || j == c){
                    edgeline = 1;
                }
                line = 1;
            }
            if(tp && (j == 1 || j == c))
                edge = 1;
        }
        /* corner */
        corner = a[1][1] | a[r][1] | a[r][c] | a[1][c];

        if(counts == 0)
            res = -1;
        else if(counts == r*c)
            res = 0;
        else if(edgeline)
            res = 1;
        else if(line || corner)
            res = 2;
        else if(edge)
            res = 3;
        else 
            res = 4;
        if(res >= 0) 
            cout << res << endl;
        else 
            cout << "MORTAL" << endl;
    }

}

int main() {
    init_cin();
    solve();
    return 0;
}
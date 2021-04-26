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

// 样例不过：细节问题（边界的处理，变量的初始化等等）
// 审题出现问题（以后审题至少审两遍，第二遍要纠正第一遍审题的理解偏差）

const int N = 4e5 + 5;
ll cnt[20][20], dp[1 << 20];
vi g[20];

void solve() {
    int n, x;
    int pos1, pos2;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        x--;
        g[x].push_back(i);
    }
    for(int i = 0; i < 20; i ++){
        for(int j = 0; j < 20; j++){
            ll count = 0;
            if(i == j) continue;
            if(g[i].empty() || g[j].empty()) continue;
            for(pos1 = g[i].size()-1, pos2 = 0; g[i][pos1] > g[j][pos2] 
                && pos1 >= 0 && pos2 < g[j].size(); ){
                count++;
                pos1--;
                pos2++;
            }
            cnt[i][j] = count;
        }
    }

    FOR(i, 0, 19){
        FOR(j, 0, 19){
            cout << cnt[i][j] << ' ';
        }cout << endl;
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < (1 << 20); i++){
        vi was;
        for(int k = 0; k < 20; k++){
            if(i & (1 << k))
                was.push_back(k);
        }
        for(int k = 0; k < 20; k++){
            if(i & (1 << k))
                continue;
            ll nmask = i | (1<<k), add = 0;
            for(int j: was){
                add += cnt[k][j];
            }
            dp[nmask] = min(dp[nmask], dp[i] + add);
        }
    }
    cout << dp[(1 << 20)-1] << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
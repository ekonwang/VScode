#include <bits/stdc++.h>                                                     //*
#define il inline                                                            //*
#define ll long long                                                         //*
#define INT __int64                                                          //*
#define usn unsigned                                                         //*
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
#define MAXLL 0x7fffffffffffffff                                             //*
#define MAXINT 0x7fffffff                                                    //*
const int INF = 0x3f3f3f3f;                                                  //*
const ll INF_LL = 9223372036854775807LL;                                     //*
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
using namespace std;     

int cmp(pair<int,int>a,pair<int,int>b){
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
//---------------------------------------------------------------------------//*



const int N = 200000 + 5;
int dp[N], r[N], n, m, d;
pair<int, int> a[N];
queue<int> q;

// 贪心算法

void solve() {
    ll ans = 0;
    cin >> n >> m >> d;
    FOR(i, 1, n) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1, cmp);
    
    //FOR(i, 1, n) cout << a[i].first << ' '; cout << endl;
    //FOR(i, 1, n) cout << a[i].second << ' '; cout << endl << endl;

    FOR(i, 1, n) {
        
        if(q.empty() || a[q.front()].first + d >= a[i].first) {
            dp[i] = ++ans;
        }else{
            dp[i] = dp[q.front()];
            q.pop();
        }
        q.push(i);
    }
    FOR(i, 1, n) {
        r[a[i].second] = dp[i];
    }
    cout << ans << endl;
    FOR(i, 1, n) {
        cout << r[i] << " ";
    }
}

int main() {
    init_cin();
    solve();
    return 0;
}
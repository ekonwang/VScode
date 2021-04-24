    #include <bits/stdc++.h>                                                     //*
    #define il inline                                                            //*
    #define ll long long                                                         //*
    #define INT __int64                                                          //*
    #define usn unsigned                                                         //*
    #define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
    #define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
    using namespace std;
    typedef struct{
        int l, r, index;
    }node;
    typedef vector<int> vi;
    ll const MAXLL = 0x7fffffffffffffffLL;                                       //*
    int const MAXINT = 0x7fffffff;                                               //*
    const int INF = 0x3f3f3f3f;                                                  //*
    const double E = exp(1.0);                                                   //*
    const double PI = acos(-1.0);                                                //*
    ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}                            //*
    int gcd(int a,int b){while(b^=a^=b^=a%=b);return a;} 
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
    inline ll read(){                                                            //*
        char ch = getchar(); ll x = 0, f = 1;                                    //*
        while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}      //*
        while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}   //*
        return x * f;                                                            //*
    }                                                                            //*                                                                         //*
    void init_cin(){                                                             //*
    std::ios::sync_with_stdio(false);                                            //*
    std::cin.tie(nullptr);                                                       //*
    std::cout.tie(nullptr);                                                      //*
    }                                                                            //*
    //---------------------------------------------------------------------------//*









const int N = 1e5 + 1;
int a[N], go[N], dp[20][N], n, q, l, r, isp[N], recent[N];
vi g[N];
void solve(){
    /* 这个计算prime的算法真快啊 */
    for(int i = 2; i < N; i++){   // 从2开始 
        if(isp[i])
            continue;
        else{
            for(int j = i; j < N; j+=i){
                isp[j] = 1;
                g[j].push_back(i);
            }
        }
    }
    cin >> n >> q;
    FOR(i, 1, n)
        cin >> a[i];
    go[n+1] = n+1;
    REP(i, n, 1){
        int j = n+1;
        for(int elem: g[a[i]]) {   // g[n+1] 初始化
            j = recent[elem] ? min(j, recent[elem]) : j; 
            recent[elem] = i; 
        }
        go[i] = min(go[i+1], j);
    }
    FOR(i, 1, n)
        dp[0][i] = go[i];
    FOR(i, 1, 19){
        FOR(j, 1, n){
            dp[i][j] = dp[i-1][j] <= n? dp[i-1][dp[i-1][j]]: n+1;
            //cout << dp[i][j] << ' ';
        }//cout << endl;
    }
    while(q--){
        int res = 0, i;
        cin >> l >> r;
        for(i = 17; i >= 0; i--){  //i的更新有一个问题
            if(dp[i][l] <= r){
                res += 1 << i;
                l = dp[i][l];
            }
        }
        cout << res + 1 << endl;
    }
}
int main() {
    init_cin();
    solve();
    return 0;
}
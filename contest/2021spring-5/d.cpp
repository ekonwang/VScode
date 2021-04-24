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
    std::ios::sync_with_stdio(false);                                            //*
    std::cin.tie(nullptr);                                                       //*
    std::cout.tie(nullptr);                                                      //*
    }                                                                            //*
    using namespace std;                                                         //*

    int cmp(pair<int,int>a,pair<int,int>b){
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
    void clear(queue<int>& q) {
        queue<int> empty;
        swap(empty, q);
    }
    //---------------------------------------------------------------------------//*

    //更新过程理解有问题

    const int N = 200 + 2;
    int R, G, B, dp[N][N][N], a[N], b[N], c[N];

    int cmp1(int x, int y) {
        return x > y;
    }

    void solve() {
        int rs = 0;
        memset(dp, 0, sizeof(dp));
        cin >> R >> G >> B;
        FOR(i, 1, R) cin >> a[i];
        FOR(i, 1, G) cin >> b[i];
        FOR(i, 1, B) cin >> c[i];
        sort(a+1, a+R+1, cmp1); 
        sort(b+1, b+G+1, cmp1);
        sort(c+1, c+B+1, cmp1);
        FOR(i, 0, R)FOR(j, 0, G)FOR(k, 0, B) {
            //if((i + j + k) % 2) continue;
            //cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << ' ';
            if(i-1 >= 0 && j-1 >= 0)
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + a[i]*b[j]);
            if(i-1 >= 0 && k-1 >= 0)
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + a[i]*c[k]);
            if(j-1 >= 0 && k-1 >= 0)
                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + b[j]*c[k]);
            //cout << dp[i][j][k] << endl;
            rs = max(rs, dp[i][j][k]);
        }
        cout << rs << endl;
    }

    int main() {
        init_cin();
        solve();
        return 0;
    }
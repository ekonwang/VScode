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



const int N = 100000 + 5;
int n;
set<int> coprimes;

void solve() {
    cin >> n;
    ll r = 1;
    FOR(i, 1, n-1) {
        if(gcd(i, n) == 1) {
            coprimes.insert(i);
            r *= i;
            r %= n;
        }
    }
    if(r != 1) coprimes.erase(r);
    cout << coprimes.size() << endl;
    for(auto i = coprimes.begin(); i != coprimes.end(); i++)
        cout << *i << ' ';
    cout << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
    #include <bits/stdc++.h>                                                     //*
    #define il inline                                                            //*
    #define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)              //*
    #define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)              //*
    typedef long long ll;                                                        //*
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



const int N = 100 + 5, M = 1e5 + 2;
int n, a[N], b[N], sum = 0, c[M];

int odd(){
    FOR(i, 1, n){
        if(a[i] & 0x1)
            return i;
    }
    return 0;
}

// 这个算法有问题
int right_caneq(){
    memset(c, 0, sizeof(c));
    c[0] = 1;
    FOR(i, 1, n){
        REP(j, M-1, a[i]) {
            c[j] |= c[j-a[i]];
        }
    }
    return c[sum/2];
}

int caneq() {
    int lsum = 0, rsum = 0, p = n;
    vector<int> ls, rs;
    while(p > 0){
        while(lsum <= rsum && p > 0){
            cout << "-> lsum " << sum << ' ' << lsum << ' ' << rsum <<  ' ' << b[p] << endl;  
            ls.push_back(b[p]);
            lsum += b[p--];
        }
        while(rsum < lsum && p > 0) {
            cout << "-> rsum " << sum << ' ' << lsum << ' ' << rsum << ' ' << b[p] << endl;  
            rs.push_back(b[p]);
            rsum += b[p--];
        } 
    }
    cout << endl;
    for(auto i = ls.begin(); i != ls.end(); i++)
        cout << *i << ' ';
        cout << endl << endl;
    for(auto i = rs.begin(); i != rs.end(); i++)
        cout << *i << ' ';
        cout << endl << endl;
    
    REP(i, n, 1) {
        cout << b[i] << ' ';
    }cout << endl;
    cout << sum << " " << lsum << " " << rsum << endl; 
    
    return rsum == lsum;
}

int need(){
    int p;
    if(sum & 0x1) return 0;

    if(!right_caneq()) return 0;

    while(!(p = odd())) {
        FOR(i, 1, n){
            a[i] /= 2;
        }
    }
    return p;
}

void solve() {
    int r = 0;
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        b[i] = a[i];
        sum += a[i];
    }
    sort(b + 1, b + n + 1);
    if((r = need())){
        cout << 1 << endl << r << endl;
        return;
    }
    cout << 0 << endl;
    
}

int main() {
    init_cin();
    solve();
    return 0;
}
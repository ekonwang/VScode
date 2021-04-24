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
        while(tmp % d == 0) {tmp /= d; cnt ++;} if(cnt) ans -= ans / d; d++;
    }
    if(tmp > 1) ans -= ans/tmp; 
    return ans;
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
  std::ios::sync_with_stdio(false);                                          //*
  std::cin.tie(nullptr);                                                     //*
  std::cout.tie(nullptr);                                                    //*
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

//没有充分理解题意
//debug上浪费了太长的时间
//边界情况没有处理好 （N的取值，string的越界访问等）

const int N = 100000 + 5;
int **pre, ls, lt;
string s, t;

bool valid() {
    FOR(i, 0, lt-1){
        //std::cout << "valid i " << i << endl; 
        int tp = t[i] - 'a';
        if(pre[tp][0] < 0) return 0;
    }
    return 1;
}

void prepare() {
    cin >> s >> t;
    ls = s.length();
    lt = t.length();
    FOR(i, 0, 25)FOR(j, 0, N-1) pre[i][j] = -1;
    //std::cout << "h" << endl;
    FOR(i, 0, 25) REP(j, ls-1, 0) {
        int tp = s[j] - 'a';
        if(tp == i) pre[i][j] = j;
        else pre[i][j] = pre[i][j+1];
    }
    /* FOR(i, 0, 25) {
        int j = 0;
        while(pre[i][j] != -1) std::cout << pre[i][j++] << ' ';
        std::cout << endl;
    }  */
}

void solve() {
    int tq;
    cin >> tq;
    
    pre = new int*[26];
    FOR(i, 0, 25){
        pre[i] = new int[N];
    }

    while(tq--) {
        //p is pos of t
        //tp is char
        //i is pos of s
        int res = 0, p = 0, tp, i = 0;
        prepare();
        if(!valid()) {
            std::cout << -1 << endl;
            continue;
        }
        p = 0;
        while(1) {
            tp = t[p]-'a';
            while((i = pre[tp][i]) >= 0 && p < lt) {
                //std::cout << "i " << i << endl;
                p++;
                i++;
                //std::cout << "p lt " << p << ' ' << lt << endl;
                if(p < lt) tp = t[p] - 'a';
            }
            res ++;
            //cout << "res " << res << endl; 
            i = 0;
            if(p >= lt) break;
        }
        std::cout << res << endl;
    }
    FOR(i, 0, 25)
        delete []pre[i];
    delete []pre;
}

int main() {
    init_cin();
    solve();
    return 0;
}
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



const double pi = 3.14159265;
int n;
double xi, yi, xh, yh, xr, yr, xo, yo, r;

void solve() {
    double t, delta;
    cin >> n;
    cin >> xi >> yi >> xh >> yh;
    xo = (xi + xh) / 2;
    yo = (yi + yh) / 2;
    r = sqrt((xi - xo) * (xi - xo) + (yi - yo) * (yi - yo));
    xi -= xo;
    yi -= yo;
    xh -= xo;
    yh -= yo;
    //t = atan(yi / xi);
    t = atan2(yi , xi);
    delta = 2 * PI / (double)n;
    if(yi == 0.0) {
        if(xi < 0.0) t += pi;
    }else{
        if(yi < 0.0) t += pi;
    }
    xr = cos(t + delta) * r;
    yr = sin(t + delta) * r;
    xr += xo;
    yr += yo;
    //cout << "r " << r << "t " << t * 180.0 / pi << "delta " << delta * 180.0 / pi << endl; 
    cout << setprecision(15) << xr << " " << yr << endl;
}

int main() {
    init_cin();
    solve();
    return 0;
}
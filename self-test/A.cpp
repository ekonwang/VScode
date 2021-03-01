#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 1000010;

il LL tackle(LL p, LL arg){
    LL tmp;
    tmp = p/arg;
    if(p%arg) tmp ++;
    return tmp*arg - p;
}

il void solve() {
    LL p, a, b, c, res;
    cin >> p >> a >> b >> c;
    res = min(tackle(p, a), tackle(p, b));
    res = min(res, tackle(p, c));
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    LL t = 0;
    cin >> t;
    For(i, 1, t)
        solve();
    return 0;
}
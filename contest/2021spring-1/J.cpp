#include <bits/stdc++.h>
using namespace std;

#define il inline
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)
#define MAXLL 0x7fffffffffffffff
#define MAXINT 0x7fffffff

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 100000 + 5;
LL t, n, p, k, x, y, dp[N]; 
string s;

il void solve() {
    cin >> t;
    while(t--){
        LL res = MAXLL;
        cin >> n >> p >> k;
        cin >> s;
        s = '0' + s;
        cin >> x >> y;
        for(int i = n; i >= p; i--) {
            dp[i] = (i + k > n ? 0 : dp[i+k]) + (s[i] == '1' ? 0: x);
            res = min(res, dp[i] + (i - p) * y);
        } 
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

//三元运算符注意括号 
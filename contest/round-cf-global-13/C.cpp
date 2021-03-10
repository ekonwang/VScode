#include <bits/stdc++.h>
using namespace std;
// brute force
// brute force can't solve.
#define il inline
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)
#define all(x) = (x).begin(),(x).end()
#define rall(x) = (x).rbegin(),(x).rend()

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 5001;
LL n, t, a[N] = {0}, cnt[N];

il void solve(){
    cin >> t;
    while(t--){
        LL res = 0;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        FOR(i, 0, n-1) cin >> a[i];
        FOR(i, 0, n-1) {
            LL tmp = cnt[i];
            if(tmp < a[i] - 1) {
                res += a[i] - 1 - tmp;
                cnt[i] += a[i] - 1 - tmp;
            }
            cnt[i+1] += cnt[i] - a[i] + 1;
            
            FOR(j, i+2, min(n-1, a[i] + i)) cnt[j] ++;
        }
        cout << res << endl;
    }
}
// il int check(){
//     int res = 0;
//     For(i, 1, n) if(a[i] != 1) return i;
//     return 0;
// }

// il LL norm(LL res){
//     int pos = 1, tmp;
//     while(pos = check()){
//         if(a[pos] > n) { res += a[pos] - n; a[pos] = n; continue; } 
//         res++;
//         while(pos <= n){
//             tmp = a[pos];
//             a[pos] = max(1, a[pos]-1);
//             pos += tmp;
//         }
//     }
//     return res;
// }

// il void solve() {
//     LL res;
//     cin >> t;
//     while(t--){
//         res = 0;
//         cin >> n;
//         For(i, 1, n) cin >> a[i];
//         res = norm(res);
//         cout << res << endl;
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
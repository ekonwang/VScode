#include <bits/stdc++.h>
using namespace std;
// brute force
// brute force can't solve.
#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 5001;
int n, t, a[N] = {0};

il int check(){
    int res = 0;
    For(i, 1, n) if(a[i] != 1) return i;
    return 0;
}

il void solve() {
    int res, pos, tmp;
    cin >> t;
    while(t--){
        res = 0;
        pos = 1;
        cin >> n;
        For(i, 1, n) cin >> a[i];
        while(pos = check()){
            res++;
            while(pos <= n){
                tmp = a[pos];
                a[pos] = max(1, a[pos]-1);
                pos += tmp; 
            }
        }
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
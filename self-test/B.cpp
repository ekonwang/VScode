#include <bits/stdc++.h>
using namespace std;
// 一道字典序问题的题目
// 将原问题转化为寻找最大字典序的问题
#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 100010;
int a[N] = {0}, b[N] = {0}, n = 0, cnt_max = 0;

il int rec(int k){
    int pos = k;
    while(a[pos] != cnt_max) b[a[pos--]] = 1; b[a[pos]] = 1;
    For(i, pos, k) cout << a[i] << ' ';
    while(b[cnt_max]){cnt_max --;}
    return pos-1; 
}

il void solve() {
    int tmp;
    cin >> n;
    For(i, 1, n) cin >> a[i];
    tmp = n;
    cnt_max = n;
    memset(b, 0, sizeof(b));
    while(tmp = rec(tmp)){}
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    For(i, 1, t) solve();
    return 0;
}
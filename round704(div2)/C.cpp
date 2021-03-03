#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define Rep(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 200010;
string str, substr;
int len, sublen, Left[N] = {0}, Right[N] = {0};

il void solve() {
    int pos, res = 0;
    cin >> len >> sublen >> str >> substr;
    pos = 0;
    For(i, 0, sublen-1){
        while(str[pos] != substr[i]) pos++;
        Left[i] = pos++;
    }
    pos = len-1;
    Rep(i, sublen-1, 0){
        while(str[pos] != substr[i]) pos--;
        Right[i] = pos--;
    }
    For(i, 1, sublen-1) res = max(res, Right[i] - Left[i-1]);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
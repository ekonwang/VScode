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
LL t, len;
string s;

il void solve() {
    cin >> t;
    while(t--){
        int con = 0, zero = 0, f = 0;
        cin >> s;
        len = s.length();
        if(s[0] == '0') zero = 1;
        FOR(i, 1, len-1){
            if(!zero && s[i] == '1') con = 1;
            if(zero && s[i] == '0' && con) {
                f = 1;
                break;
            }
            if(s[i] == '0') zero = 1; 
            else zero = 0;
        }
        if(f) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
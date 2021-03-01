#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

const int N = 1000010;

// when a == 0 or 1, c can only be 0.
// when a >= 2, 0 <= c <= b.
il void solve() {
    int a, b, c;
    cin >> b >> a >> c;
    if(!a){
        cout << "No" << endl; 
    }else if(a == 1){
        if(!c) {
            cout << "Yes" << endl;
            For(j, 0, 1){
                cout << '1';
                For(i, 1, b) cout << '0';
                cout << endl;
            }
        }
        else cout << "No" << endl;
    }else{
        if(c > b) cout << "No" << endl;
        else{
            cout << "Yes" << endl;

            cout << "11";
            For(i, 1, b) cout << '0';
            For(i, 1, a-2) cout << '1';
            cout << endl;

            cout << '1';
            For(i, 1, c) cout << '0';
            cout << '1';
            For(i, 1, b-c) cout << '0';
            For(i, 1, a-2) cout << '1';
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

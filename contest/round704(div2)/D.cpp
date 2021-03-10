#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define all(x) = (x).begin(),(x).end()
#define rall(x) = (x).rbegin(),(x).rend()

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

template<class T> ostream &operator << (ostream& out, const vector<T>& arr) {
    cout << "{"; for (int i = 0; i < arr.size(); i++)cout << (!i ? "" : ", ") << arr[i]; cout << "}";
    return out;
}
template<class T> ostream &operator << (ostream& out, const vector<vector<T> >& arr) {
    cout << "{\n"; for (auto& vec : arr)cout << "  " << vec << ",\n"; cout << "}";
    return out;
}
template<class S,class T> ostream &operator << (ostream& out, const pair<S,T>& p){
    cout << "{" << p.first << "," << p.second << "}" << '\n';
    return out;
}
template<class T> istream &operator >> (istream& in, vector<T>& arr) {
    for (auto& i : arr)cin >> i; return in;
}
template<class S,class T> istream &operator >> (istream& in,pair<S,T>& p){
    cin >> p.first >> p.second; return in;
}

const int N = 1000010;
/////////////////////////////////////////////////////////////////////////////////////////
// when a == 0 or 1, c can only be 0.
// when a >= 2, 0 <= c <= b.
il void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if(!a || b == 1) 
        if(!k) {
            cout << "Yes" << endl; 
            For(i, 1, 2) {For(i, 1, b) cout << 1; For(i, 1, a) cout << 0; cout << endl;}
        }
        else cout << "No" << endl;
    else{
        if(k <= a){
            cout << "Yes" << endl;
            For(i, 1, b) cout << 1; For(i, 1, a) cout << 0; cout << endl;
            For(i, 1, b-1) cout << 1; For(i, 1, k) cout << 0; cout << 1; For(i, 1, a-k) cout << 0; cout << endl; 
        }else if(k <= a + b - 2){
            cout << "Yes" << endl;
            For(i, 1, b) cout << 1; For(i, 1, a) cout << 0; cout << endl;
            if(k <= b-1){
                For(i, 1, b-k) cout << 1; cout << 0; For(i, 1, k) cout << 1; For(i, 1, a-1) cout << 0; cout << endl;
            }else{
                cout << 1; cout << 0; For(i, 1, b-2) cout << 1; For(i, 1, k+1-b) cout << 0; cout << 1; For(i, 1, a+b-2-k) cout << 0; cout << endl;
            }
        }else cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}

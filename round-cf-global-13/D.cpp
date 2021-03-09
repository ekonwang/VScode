#include <bits/stdc++.h>
using namespace std;

#define il inline
#define FOR(i,a,b) for(int i = (a), (i##i)=(b); i<=(i##i); ++i)
#define REP(i,a,b) for(int i = (a), (i##i)=(b); i>=(i##i); --i)
#define all(x) = (x).begin(),(x).end()
#define rall(x) = (x).rbegin(),(x).rend()

typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double LD;

template<class T> ostream& operator << (ostream& out, const vector<T>& arr) {
    cout << "{"; for (int i = 0; i < arr.size(); i++)cout << (!i ? "" : ", ") << arr[i]; cout << "}";
    return out;
}
template<class T> ostream& operator << (ostream& out, const vector<vector<T> >& arr) {
    cout << "{\n"; for (auto& vec : arr)cout << "  " << vec << ",\n"; cout << "}";
    return out;
}
template<class S, class T> ostream& operator << (ostream& out, const pair<S, T>& p) {
    cout << "{" << p.first << "," << p.second << "}" << '\n';
    return out;
}
template<class T> istream& operator >> (istream& in, vector<T>& arr) {
    for (auto& i : arr)cin >> i; return in;
}
template<class S, class T> istream& operator >> (istream& in, pair<S, T>& p) {
    cin >> p.first >> p.second; return in;
}

const int N = 1000010;
// The algorithm based on a very concise conclusion : 
// u can convert to v if and only if : 1) u's significant bits more than v; 2) v's every bits is no lower than
// the corresponding bit in u; 3) v bigger than u; 
il void solve(){
    
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
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

const int N = 100100;
int n, m, r, c, t;

il void solve() {
    cin >> t;
    while(t--){
        cin >> n >> m >> r >> c;
        int res = 0, tp;  //命名冲突
        tp = abs(n - r) + abs(m - c);

        res = max(tp, res);
        tp = abs(1 - r) + abs(m - c);


        res = max(tp, res);
        tp = abs(n - r) + abs(1 - c);


        res = max(tp, res);
        tp = abs(1 - r) + abs(1 - c);

        res = max(tp, res);
        cout << res << endl;  //顾头不顾尾
    }
}
// 为什么我写的代码总是有一些莫名其妙的错误
int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
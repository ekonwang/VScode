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
LL t, n, k, s[5010], x[5010], y[5010], ans[5010];


il void solve() {
    cin >> n;
    FOR(i, 1, n) {cin >> x[i] >> y[i]; }
    ans[1] = 1;
    LL cnt = s[1] = 1; 
    FOR(i, 2, n) {
        LL tp = 0, ch, mul;
        FOR(j, 1, n) {
            if(s[j]) continue;
            mul = (x[cnt] - x[j]) * (x[cnt] - x[j]) + (y[cnt] - y[j]) * (y[cnt] - y[j]);
            if(tp >= mul) continue;
            tp = mul;
            ch = j;
        }
        s[ch] = 1;
        cnt = ch;
        ans[i] = cnt;
    }
    FOR(i, 1, n) cout << ans[i] << ' '; cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
/* 还有什么特殊情况？？？？ */
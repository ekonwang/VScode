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
LL t, n, k, s[121], c[121], a[121];

il void pre(){
    memset(s, 0, sizeof(s));
    memset(c, 0, sizeof(c));
    FOR(i, 1, n){
        LL v;
        cin >> v;
        // if (c[v] >= k || c[v] <= 0) { s[v] ++;} 
        if (c[v] == 0) { s[v] ++;}

        /* FOR(j, 1, 100){
            if(c[j] >= 0) c[j] ++;
        } */

        FOR(j, 1, 100){
            c[j] = (c[j] + 1) % k;
        }
        c[v] = 0;
    }
}

il void solve() {
    cin >> t;
    while(t--){
        cin >> n >> k;
        pre();
        LL m = 0;
        FOR(i, 1, 100) m = max(s[i], m);

        if(n == m) cout << 0 << endl;
        else cout << (n - m - 1) / k + 1 << endl;
        // res = (n- max(s) - 1)/k + 1
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
/* 还有什么特殊情况？？？？ */
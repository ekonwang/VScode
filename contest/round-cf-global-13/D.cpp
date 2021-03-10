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
    int t, u, v, f;
    cin >> t;
    while(t--) {
        f = 0;
        cin >> u >> v;
        vector <int> vec_u, vec_v;
        int size_v;
        if(u > v) {cout << "No" << endl; continue; }
        else if(u == v) {cout << "Yes" << endl; continue; }
        else {
            FOR(i, 0, 30) {
                int tmp = 1 << i;
                if(tmp & u) vec_u.push_back(i);
                if(tmp & v) vec_v.push_back(i); 
            }
            if (vec_u.size() < (size_v = vec_v.size())) {cout << "No" << endl; continue; }
            FOR(i, 0, size_v-1) if(vec_u[i] > vec_v[i]) {cout << "No" << endl; f = 1; break; }
            if(!f) cout << "Yes" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
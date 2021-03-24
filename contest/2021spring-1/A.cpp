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
LL t, q, v, d, b[10], c[10];
il void p(){
    c[0] = 1;
    FOR(i, 1, 9) c[i] = c[i-1] * 10;
}
il void pre(){
    b[0] = d;
    FOR(i, 1, 9) b[i] = b[i-1] * 10;
}

bool ifv(LL a){
    if(a <= 0) return false;
    LL tp = a;
    REP(i, 9, 0) { 
        if(tp / c[i] == d) return true;    //xiafan 这里写错导致浪费了大量时间
        tp %= c[i];
    }
    FOR(i, 0, 9) {
        if (ifv(a - b[i])) return true;
    }
    return false;
}

void solve() {
    cin >> t;
    p();
    while(t--){
        cin >> q >> d;
        pre();
        while(q --){
            cin >> v;
            if(ifv(v)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
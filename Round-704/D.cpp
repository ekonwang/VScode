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

const LL N = 100010;

il void solve() {
    LL n, a[N], dk, ik, ps, v, b, dr = 0, ir = 0, dm = 0, im = 0, tp;
    cin >> n >> b;
    // get a[n]
    FOR(i, 1, n-1) {
        cin >> v;
        if(v > b) a[i] = 1;
        else a[i] = -1;
        b = v;
    }a[0] = -a[1];
    // trival case
    if(n == 1) cout << 1 << endl;
    // get longest
    ps = 1;
    while(ps <= n-1){
        tp = 2;
        if(a[ps] < 0) {
            while(ps < n-1 && a[ps] + a[ps+1]) {ps++; tp ++;}
            if (tp > dm) {
                dr = 0;
                dm = tp;
                dk = ps;
            }else if(tp == dm) dr = 1;
            ps++;
            continue;
        }
        while(ps < n-1 && a[ps] + a[ps+1]) {ps++; tp++; }
        if(tp > im) {
            ir = 0;
            im = tp;
            ik = ps;
        }else if(tp == im) ir = 1;
        ps ++;
    }
    // 
    if(im != dm || ir || dr || dk - ik + 1 != im || dm % 2 == 0) {
        cout << 0 << endl;
        return;
    }else cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
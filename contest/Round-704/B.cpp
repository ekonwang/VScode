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

const int N = 100010;
/////////////////////////////////////////////////////////////////////////////////////////

il void solve() {
    LL t, n, k, v, a[N], Max, Mex, sum, mid, f;
    cin >> t;
    while(t--){
        Mex = -1; 
        f = 0;
        set<LL> s;
        cin >> n >> k;
        FOR(i, 0, n-1) {
            cin >> v;
            s.insert(v);
            a[i] = v;
        }
        sort(a, a+n);

        Max = a[n-1];
        // if a begin with 0:
        if (!a[0])
        FOR(i, 1, n-1) {
            if(a[i] > a[i-1] + 1) Mex = a[i-1] + 1; 
        }else Mex = 0;
        if(Mex == -1) Mex = a[n-1] + 1;
        // you can also use MAP.
        mid = (Mex + Max + 1)/2;
        FOR(i, 0, n-1) if(a[i] == mid) f = 1;

        sum = s.size();
        if(!k) cout << sum << endl;
        else if(Mex > Max) cout << sum + k << endl;
        else if(!f) cout << sum + 1 << endl;
        else cout << sum << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
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
il double Sqrt(LL ar){
    double r = ar, l = 0, p = 1e-12, mid, dl;
    mid = (r + l)/2;
    dl = mid * mid;
    while(fabs(dl - ar) > p){
        if(dl > ar) r = mid;
        else l = mid;
        mid = (r + l)/2;
        dl = mid * mid;
    }
    return mid;
}

il void solve() {
    LL t, n, x, y, a[N], b[N];
    double r;
    cin >> t;
    while(t--){
        cin >> n;
        r = 0;
        LL tp = 2*n, pos_x = 0, pos_y = 0;
        FOR(i, 1, tp){
            cin >> x >> y;
            if(!x) b[++pos_y] = abs(y);
            else a[++pos_x] = abs(x);
        }
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        FOR(i, 1, n) {
            // so : How to output result with high precision.
            // The type of data influences precision
            // U made it. But a little bit too late.
            // from now on, use LL, no int any more.
            LL tpx = a[i], tpy = b[i];
            r += Sqrt(tpx * tpx + tpy * tpy);
        }
        cout << setprecision(20) << r << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
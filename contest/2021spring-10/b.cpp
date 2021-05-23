#include <bits/stdc++.h>                                                     //*
#define FOR(i,a,b) for(int (i) = (a); i <= (b); ++i)                         //*
#define FORN(i,n) for(int (i) = (0); i < n; ++i)
#define REP(i,a,b) for(int (i) = (a); i >= (b); --i)                         //*
using namespace std;                                                         //*
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef struct{int lchild, rchild, index; } node;
const ll MAXLL = 0x7fffffffffffffffLL;                                       //*
const int MAXINT = 0x7fffffff;                                               //*
const int INF = 0x3f3f3f3f;                                                  //*
const double E = exp(1.0);                                                   //*
const double PI = acos(-1.0);                                                //*
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}                            //*
ll lcd(ll a , ll b){return a * b / gcd(a,b);}                                //*
ll phi(ll a) {                                                               //*
    ll tmp = a, ans = a, d = 2;                                              //*
    while(d * d <= tmp) {                                                    //*
        ll cnt = 0;                                                          //*
        while(tmp % d == 0) {tmp /= d; cnt ++;} if(cnt) ans -= ans / d; d++; //*
    }                                                                        //*
    if(tmp > 1) ans -= ans/tmp;                                              //*
    return ans;                                                              //*
}
void init_cin(){                                                             //*
std::ios::sync_with_stdio(false);                                            //*
std::cin.tie(nullptr);                                                       //*
std::cout.tie(nullptr);                                                      //*
}                                                                            //*
//---------------------------------------------------------------------------//*

const int N = 100000 + 5;
int t;
#define DEBU
bool lexi_cmp(string s1, string s2){
    int len1 = s1.length(), len2 = s2.length(), lens = min(len1, len2), dif = -1;
    for(int i = 0; i < lens; i++){
        if(s1[i] != s2[i]) {
            dif = i;
            break;
        }
    }
    if(dif == -1) {
        if(len1 < len2) return true;
        else return false;
    }
    #ifdef DEBUG
        cout << '\t' << s1[dif] << ' ' << s2[dif] << endl; 
    #endif
    return s1[dif] < s2[dif];
}

string sort_str(string s){
    string ret = s;
    int len = s.length();
    int a[N], b[N], dif = -1, found = -1;
    for(int i = 0; i < len; i++){
        a[i] = s[i] - 'A';
        b[i] = a[i];
    }
    sort(a, a+len);
    #ifdef DEBUG
        for(int i = 0; i < len; i++) cout << a[i] << ' '; cout << endl;
        for(int i = 0; i < len; i++) cout << b[i] << ' '; cout << endl;
    #endif
    for(int i = 0; i < len; i++){
        if(a[i] != b[i]){
            dif = i;
            break;
        }
    }
    if(dif < 0){
        return s;
    }
    for(int i = len-1; i >= 0; i--){
        if(b[i] == a[dif]){
            found = i;
            break;
        }
    }
    #ifdef DEBUG
        cout << '\t' << ret << endl;
    #endif
    ret[dif] = s[found];
    ret[found] = s[dif];
    return ret;
}
void solve() {
    cin >> t;
    string s1, s2;
    while(t--){
        cin >> s1 >> s2;
        s1 = sort_str(s1);
        if(lexi_cmp(s1, s2)){
            cout << s1 << endl;
            continue;
        }
        cout << "---" << endl;
        #ifdef DEBUG
            cout << '\t' << s1 << endl;
        #endif
    }
}

int main() {
    init_cin();
    solve();
    return 0;
}
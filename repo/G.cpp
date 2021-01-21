#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define N 10010

void sol(){
    set< pair<string, string> > pair_set;
    map< pair<string, string>, int> queried;
    string str[N], qA, qB;
    int n = 0, q = 0, len[N];
    cin >> n;
    for(int k = 1; k <= n; k++){
        cin >> str[k];
        len[k] = str[k].length();
    }
    cin >> q;
    for(int j = 1; j <= q ; j++){
        cin >> qA >> qB;
        int res = 0;
        pair<string, string> tmp = make_pair(qA, qB);
        if(pair_set.count(tmp) ) cout << queried[tmp] << endl;
        else{
            for(int k = 1; k <= n; k++){
                if(len[k] >= qA.length() && str[k].substr(0, qA.length()) == qA) res++;
                else if(len[k] >= qB.length() && str[k].substr(len[k]-qB.length()) == qB ){
                    res++;
                }
            }
            pair_set.insert(tmp);
            queried[tmp] = res;
            cout << res << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define N 10010

void sol(){
    int t, h, val, res;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> h;
		res = 0;
		for(int j = 0; j < h; j++) {
			cin >> val;
			res ^= val;
		}
		if(res) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
    return 0;
}

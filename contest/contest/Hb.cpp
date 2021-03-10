#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
#define N 500001
int a[N] = { 0 }, b[N] = { 0 }, v[N] = { 0 }, s[N] = { 0 };
int next(int cur) {
    int nxt = cur;
    while (nxt) {
        nxt = a[nxt];
        if (b[nxt]) break;
    }
    return nxt;
}
void sol() {
    int n, m, val, res = 0, can;
    cin >> n >> m;
    a[1] = 0; s[0] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> val;
        a[i] = val;
    }
    for (int i = 1; i <= m; i++) {
        cin >> val;
        b[val] = 1;
    }
    for (int k = 1; k <= n; k++) {
        if (b[k]) {
            int tmp = next(k);
            s[k] = s[tmp] + 1;
            if (s[k] > res) res = s[k];
        }
    }
    cout << res;
}
int main() {
    ios::sync_with_stdio(0);
    sol();
    return 0;
}
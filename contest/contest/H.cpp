#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
#define N 500001
int a[N] = { 0 }, b[N] = { 0 }, v[N] = { 0 };
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
    a[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> val;
        a[i] = val;
    }
    for (int i = 1; i <= m; i++) {
        cin >> val;
        b[val] = 1;
    }
    for (int k = n; k > 0; k--) {
        if (b[k] && !v[k]) {
            can = 0;
            int tmp = k;
            while (tmp) {
                v[tmp] = 1;
                can++;
                tmp = next(tmp);
            }
            if (can > res) res = can;
        }
    }
    cout << res;
}
int main() {
    ios::sync_with_stdio(0);
    sol();
    return 0;
}
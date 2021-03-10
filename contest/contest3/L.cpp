#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define N 1001
#define Maxm 1000001
#define MaxRe 1000000000
int serve[N][N], money[N][N], select[N][N] = { 0 };
int res = MaxRe, n, m;
double ratio = MaxRe;
void search(int curn, int s, int p) {
    if (curn == n + 1) {
        double d_p = p, d_s = s, d_r = d_p/d_s;
        if (d_r < ratio) {
            ratio = p / s;
            res = p;
        }
        else if (d_r == ratio) {
            if (p < res) res = p;
        }
    }
    else {
        for (int i = 1; i <= m; i++) {
            if (!select[curn][i]) {
                int nxt_s = serve[curn][i] < s ? serve[curn][i] : s;
                int nxt_p = p + money[curn][i];
                search(curn + 1, nxt_s, nxt_p);
            }
        }
    }
}
void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        money[i][0] = Maxm;
        for (int j = 1; j <= m; j++) {
            cin >> serve[i][j] >> money[i][j];
            if (money[i][j - 1] >= money[i][j]) select[i][j - 1] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!select[1][i]) {
            search(2, serve[1][i], money[1][i]);
        }
    }
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(0);
    sol();
    //system("pause");
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#define N 100001
using namespace std;
void sol() {
    int n, m, x, y, f;
    string str;
    cin >> n >> m;
    int sign[N] = { 0 }; int sum[N] = {0};

    cin >> str;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (str[i-1] == '(') sign[i] = 1;
        else sign[i] = -1;
    }
    sum[1] = sign[1];
    for (int i = 1; i <= n; i++) {
        sum[i] = sign[i] + sum[i-1];
    }

    for (int j = 1; j <= m; j++) {
        cin >> x >> y;
        for (int k = x; k <= y; k++) sign[k] = -sign[k];

        f = 0;
        for (int i = x; i <= y; i++) {
            sum[i] = sign[i] + sum[i - 1];
            if (sum[i] < 0) {
                cout << "NO" << endl;
                f = 1;
                break;
            }
        }
        if (!f) {
            if (!sum[n]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    sol();
    //system("pause");
    return 0;
}
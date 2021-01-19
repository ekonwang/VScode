#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#define N 1000002
using namespace std;
typedef long long ll;
short pos[N] = { 0 };
void sol() {
    int n, cur, len;
    string str, pat;
    cin >> n >> str;
    pat = string(1, str[0]);
    len = 1;
    for (int i = 0; i < n; i++) {
        string sub = str.substr(0, i + 1);
        int f = 0;
        for (int j = 1; j < N; j++) {
            int p = pos[j];
            while (p <= i - j + 1) {
                pat = sub.substr(p, j);
                if (sub.find(pat) == sub.rfind(pat)) {
                    f = 1;
                    len = j;
                    cout << len << endl;
                    break;
                }
                else {
                    pos[j]++;
                    p++;
                }
            }
            if (f)break;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    sol();
    //system("pause");
    return 0;
}
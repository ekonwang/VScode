#include <bits/stdc++.h>
using namespace std;
#define N 10002

int a[N], b[N], dp[N][N] = {0}, n;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= n; j++) cin >> b[j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j]) dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
                dp[i][j] = max(dp[i][j-1], dp[i][j]);
            }
        }
    cout << dp[n][n] << endl;
}
int main(){
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
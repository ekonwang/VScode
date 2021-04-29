#include <bits/stdc++.h>
using namespace std;
const int N = 31;
const int M = 3000;
const int K = 10;
int dp[N][N*100], b[N], v[N];
int main(){
    memset(dp, 0xcf, sizeof(dp));
    dp[0][0]  =  0;
    for(int i = 1; i <= 30; i++){
        for(int j = M; j >= 0; j--){
            dp[i][j] = max(dp[i][j-b[i]] + v[i], dp[i-1][j]); 
        }
    }
    int res = 0;
    for(int i = 0; i <= M; i++){
        res = max(res, dp[30][i]);
    }
    cout << res << endl;
    exit(0);
}
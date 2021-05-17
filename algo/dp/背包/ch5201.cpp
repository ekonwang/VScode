#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4;
int dp[N], a[120];
int main(){
    int M;
    dp[0] = 1;
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j <= 10000; j++){
            if(a[j]) a[j + a[i]] ++;
        }
    }
    cout << a[M] << endl;
}
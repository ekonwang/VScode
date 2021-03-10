#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define N 502
#define MaxT 1e14
ll a[N][N] = { 0 }, b[N][N] = { 0 }, c[N][N] = { 0 }, d[N][N] = { 0 }, v[N][N] = { 0 }, t[N][N] = {0};   //c : row weight, d : collum weight
ll n, m, xs, ys, xt, yt;
ll mint = MaxT, curt = 0;
// can stay.

void dijkstra(){
    int xc = xs, yc = ys;
    for(int i = 1; i <= n * m; i++){
        ll tmp = MaxT;
        ll sum = a[xc][yc] + b[xc][yc];
        ll remain = t[xc][yc] % (sum);
        if(remain < a[xc][yc]){
            if(xc - 1 >= 1) 
                if(t[xc-1][yc] > t[xc][yc] + d[xc-1][yc]) 
                    t[xc-1][yc] = t[xc][yc] + d[xc-1][yc];
            if(xc + 1 <= n)
                if(t[xc+1][yc] > t[xc][yc] + d[xc][yc])
                    t[xc+1][yc] = t[xc][yc] + d[xc][yc];
            if(yc - 1 >= 1)
                if(t[xc][yc-1] > t[xc][yc] + c[xc][yc-1] + a[xc][yc] - remain)
                    t[xc][yc-1] = t[xc][yc] + c[xc][yc-1] + a[xc][yc] - remain;
            if(yc + 1 <= n)
                if(t[xc][yc+1] > t[xc][yc] + c[xc][yc] + a[xc][yc] - remain)
                    t[xc][yc+1] = t[xc][yc] + c[xc][yc] + a[xc][yc] - remain;
        }else{
            if(xc - 1 >= 1) 
                if(t[xc-1][yc] > t[xc][yc] + d[xc-1][yc] + sum - remain) 
                    t[xc-1][yc] = t[xc][yc] + d[xc-1][yc] + sum - remain;
            if(xc + 1 <= n)
                if(t[xc+1][yc] > t[xc][yc] + d[xc][yc] + sum - remain) 
                    t[xc+1][yc] = t[xc][yc] + d[xc][yc] + sum - remain;
            if(yc - 1 >= 1)
                if(t[xc][yc-1] > t[xc][yc] + c[xc][yc-1])
                    t[xc][yc-1] = t[xc][yc] + c[xc][yc-1];
            if(yc + 1 <= n)
                if(t[xc][yc+1] > t[xc][yc] + c[xc][yc])
                    t[xc][yc+1] = t[xc][yc] + c[xc][yc];
        }
        v[xc][yc] = 1;
        for(int j = 1; j <= n; j++){
            for(int k = 1;k <= m; k++){
                if(!v[j][k] && t[j][k] < tmp){
                    tmp = t[j][k];
                    xc = j;
                    yc = k;
                }
            }
        }
    }
}

void sol() {
    cin >> n >> m >> xs >> ys >> xt >> yt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            t[i][j] = MaxT;
        }
    }
    t[xs][ys] = 0;
    dijkstra();
    std::cout << t[xt][yt] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    sol();
    return 0;
}

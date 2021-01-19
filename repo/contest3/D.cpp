#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;
void print(vector<vector<int>> map, int n, int m){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == 1) cout << "*";
            else cout << ".";
        }
        cout << endl;
    }
}
void copy(vector<vector<int>> &map, vector<vector<int>> &next, int n){
    for(int i =1; i<=n; i++) map[i].assign(next[i].begin(), next[i].end());
}
void sol(){
    int n, m, min, max, t;
    string str;
    cin >> n >> m >> min >> max >> t;
    vector<vector<int>> map(n+2, vector<int>(m+2, 0));
    vector<vector<int>> next(map);
    for(int i = 1; i <= n; i++){
        cin >> str;
        for(int j = 1; j <= m; j++){
            if(str[j-1] == '*') map[i][j] = 1;
        }
    }
    for(int k = 1; k < t; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int sum = map[i-1][j-1] + map[i-1][j] + map[i-1][j+1] + map[i][j-1] +
                    map[i][j+1] + map[i+1][j-1] + map[i+1][j] + map[i+1][j+1];
                if(sum >= min && sum <= max) next[i][j] = 1;
                else next[i][j] = 0;
            }
        }
        copy(map, next, n);
    }
    print(map, n, m);
}
int main(){
    ios::sync_with_stdio(0);
    sol();
    //system("pause");
    return 0;
}
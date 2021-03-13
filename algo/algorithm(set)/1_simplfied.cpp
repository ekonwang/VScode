#include<bits/stdc++.h>
using namespace std;
int n, m , p, a[10001], x, y;
int fd(int x){
    if(a[x] == x)return x;
    else return a[x] = fd(a[x]);
}
void combine(int x, int y){
    a[fd(x)] = fd(y);
}
int main(){
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int j = 0; j < m; j++){
        cin >> x >> y;
        combine(x, y);
    } 
    for(int k = 0; k < p; k++){
        cin >> x >> y;
        if(fd(x) == fd(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    //system("pause");
    return 0;
}
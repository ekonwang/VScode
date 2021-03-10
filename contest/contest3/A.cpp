#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 10001
int res = 0;
void sol(){
    int n, c, p = 0;
    int a[N];
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    while(p + 2 < n){
        if(a[p + 2] - a[p] <= c){
            res ++;
            p+=3;
        }else p++;
    }
    cout << res << endl;
}


int main(){
    ios::sync_with_stdio(0);
    //sol();
    int n;
    cin >> n;
    vector<int> a(n, 1);
    for(auto i: a) cout << i << endl;
    system("pause");
    return 0;
}
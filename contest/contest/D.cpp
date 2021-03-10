#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    // k(m-1) <= n-1
    // res = C(m+dor-1, dor)
    int t, n, m, k, dor;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m >> k;
        dor = n - 1 - k*(m - 1);
        if(m == 2){
            if(dor == 0) cout << "yes" << endl;
            else if((m + dor -1) % 2) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else{
            if(dor == 0) cout << "yes" << endl;
            else if(dor == 1 && m%2) cout << "yes" << endl;
            else cout << "no" << endl; 
        }
    }
    return 0;
}
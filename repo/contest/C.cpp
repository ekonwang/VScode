#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << i << ' ';
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << 1 << ' ';
    }
    return 0;
}
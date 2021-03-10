#include <iostream>
using namespace std;
#define N 14
int a[36] = {0};
int sol(){
    int val, x = 0, y = 0;
    for(int i = 0; i < N; i++){
        cin >> val;
        a[val]++;
    }
    for(int i = 1; i < N; i++){
        if(a[i]){
            x++;
            if(!y && a[i] > 1){
                y++;x++;
            }
        }
    }
    return N - x;
}
int main(){
    //ios::sync_with_stdio(0);

    int res = sol();
    cout << res << endl;

    //system("pause");
    return 0;
}
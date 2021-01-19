#include<bits/stdc++.h>
using namespace std;
int main(){
    int res = 0, n;
    string strA_, strB_;
    map<string, int> box;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> strA_ >> strB_;
        strA_ = strA_.substr(0, 2);
        if(strA_ != strB_){
            box[strA_ + strB_]++;
            res += box[strB_ + strA_];
        }
    }
    cout << res;
    //system("pause");
    return 0;
}

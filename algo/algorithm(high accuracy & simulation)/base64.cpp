#include<bits/stdc++.h>
using namespace std;
int a[1000] = {0};
int cd[8] = {128, 64, 32, 16, 8, 4, 2, 1};
int cd2_[6] = {32, 16, 8, 4, 2, 1};
char cd3_[64];
void pre_process(){
    for(int i = 0; i < 26; i++) {
        cd3_[i] = i + 'A';
        cd3_[i + 26] = i + 'a';
    }
    for(int j = 0; j < 10; j++){
        cd3_[j + 52] = j + '0';
    }
    cd3_[62] = '+'; cd3_[63] = '/';
}
int main(){
    int n, dest, remain = 0, val, temp;
    char ch;
    pre_process();
    cin >> n;
    if(8 * n % 6) remain = 6 - (8 * n % 6);
    dest = remain + 8 * n;
    for(int i = 0; i < n; i++){
        cin >> val;
        for(int j = 0; j < 8; j++){
            temp = val / cd[j];
            val = val % cd[j];
            a[8*i + j] = temp;
        }
    }
    for(int j = 0; j < remain; j++) a[8*n + j] = 0;
    for(int i = 0; i < dest/6; i++){
        val = 0;
        for(int j = 0; j < 6; j++) val += a[6*i + j] * cd2_[j];
        ch = cd3_[val];
        cout << ch;
    }
    if(remain){
        cout << '=';
        if(remain == 4) cout << '=';
        cout << endl;
    }           
    system("pause");
    return 0;
}
//log1 不审题！！！ ‘=’可能有多个
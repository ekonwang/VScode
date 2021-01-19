#include<iostream>
#include<string>
using namespace std;
int main(){
    int value = 0, pos = 1;
    string str;
    cin >> str;
    for(int i = 0; i < 11; i++){
        if(str[i] == '-') continue;
        else value += (str[i] - '0')*pos++;
    }
    value = value % 11;
    if(value == 10) {
        if (str[12] == 'X') cout << "Right";
        else {
            str[12] = 'X';
            cout << str;
        }
    }
    else if(str[12] == (char)(value + '0')) cout << "Right";
    else {
        str[12] = (char)(value + '0');
        cout << str;
    }
    return 0; 
}
//log1 pos = 0 错误 应该为1
//log2 发现忽略了余数为10的情况，看题目不仔细

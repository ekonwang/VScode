#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int stoi_cpy(string str){
    int res = str[0] - '0';
    for(int i = 1; i < str.length(); i++){
        res *= 10; res += str[i] - '0';
    }
    return res;
}
int flag = 1, afternum = 0, arg[4] = {0}, pos = 0;
string str;
bool operation(int i = 0){
    if(afternum == 1){
        arg[pos + 1 - i] += stoi_cpy(str)*flag;
        afternum = 0; str.clear();
        if(flag == -1) flag = 1;
        return true;
    }
    return false;
}
int main(){
    char ch, var;
    string input;
    float res;
    cin >> input;
    // cout << input.length() << endl;
    for(int i = 0; i < input.length(); i++){
        ch = input[i];
        if(ch <= '9'&& ch >= '0') {
            str += ch; afternum = 1;
            if(i == input.length() - 1){
                arg[pos + 1] += stoi_cpy(str)*flag;
            }
        }else if(ch == '='){
            operation();
            pos += 2;
        }else if(ch == '-'){
            operation();
            flag = -1;
        }else if(ch == '+'){
            operation();
        }else if(ch == ' '){
            continue;
        }else{
            var = ch;
            if (!operation(1)){ arg[pos] += flag; }
        }
        /* cout << "ch: " << ch << '\t' << flag << '\t' << str << '\t';
        cout << "pos & args :" << pos << '\t' << arg[0] << '\t' << arg[1] << '\t' << arg[2] << '\t' << arg[3] << endl;  */
    }
    // temp1 = arg[0] - arg[2]; temp2 = arg[3] - arg[1];
    float t1 = arg[3] - arg[1], t2 = arg[0] - arg[2];
    res = t1/ t2;
    if (res == 0) res = 0;
    cout << var << '=';
    printf("%0.3f", res);
    //system("pause");
    return 0;
}
//log1 while(cin >> char)不能自行停止
//log2 flag = 1 的操作被写成 flag == 1
//log3 忽略了整数位于最后一位的情况
//log4 i == inpt.length() 写成 ‘=’
//log5 ‘-’ 被程序认为是 ‘?’
//log6 oj不支持负0
#include<bits/stdc++.h>
using namespace std;
string str;
int len;
int decode(int pos){
    int val = 0, flag = 0, i, subpos;
    char ch;
    if(str[pos] == '[') pos++;
    while(1){
        ch = str[pos];
        if('0' <= ch && ch <= '9'){  //log1
            flag++; pos++;
            val = val * 10 + ch - '0';
        }else break;
    } if(!flag) val = 1;
    for(i = 0; i < val; i++){
        subpos = pos;
        while(1){
            if(subpos == len) break;   //log2
            ch = str[subpos++];
            if(ch == ']') break;
            else if(ch == '['){
                subpos = decode(subpos);
            }else{
                cout << ch;
            }
        }
    }
    return subpos;
}
int main(){
    int t;
    cin >> str; len = str.length();
    t = decode(0);
    while(t != len) t = decode(t);
    system("pause");
    return 0;
}
//log1 string类型越界访问
//log2 算法逻辑问题
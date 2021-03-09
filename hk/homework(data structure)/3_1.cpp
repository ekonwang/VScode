#include<iostream>
#include<cstring>
using namespace std;

void Del(char *s, char ch){
    int len = strlen(s), i = 0, j = 0;
    char* s_copy = new char[len];
    for(i = 0; i < len; i ++){
        if (s[i] != ch) {
            s_copy[j++] = s[i];
        }
    }
    s_copy[j] = '\0';
    len = strlen(s_copy);
    for (i = 0; i <= len; i ++){          //不能通过改变形参指针s的指向使得实参指针发生指向改变，只能选择循环结构实现字符串的拷贝
        s[i] = s_copy[i];
    }
}

char firstSingle(char* str){
    int counter[26] = {0}, len = strlen(str), i = 0;
    for (i = 0; i < len; i ++){
        counter[str[i] - 'a'] ++;
    }
    for (i = 0; i < len; i++){
        if ( counter[str[i] - 'a'] == 1 ) return str[i];
    }
    return NULL;
}

int main(){
    char str[10] = "abaccdeff";
    Del(str, 'f');
    cout << str << endl;
    cout << firstSingle(str) << endl;
    system("pause");
    return 0;
}
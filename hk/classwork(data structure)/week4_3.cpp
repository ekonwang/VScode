#include<iostream>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

int Char2Num(char* ch){
    int len = strlen(ch), i, j,num[3] = {0}, result = 0;
    for(i = 0; i < len; i ++){
        num[i] = (int)(ch[i] - '0') ;
    }
    for(i = 0; i < len; i ++){
        for(j = 0; j < len - i - 1; j ++){
            num[i] *= 10;
        }
        result += num[i];
    }
    return result;
}

int main(){              //main函数后的括号
    string str;
    getline(cin, str);
    const char* strCopy = str.c_str();
    int i, j, k, l, len = strlen(strCopy);
    for(i = 0; i <= 2 && i < len && len <= 12; i ++){
        for(j = i + 1; j <= i + 3 && j < len; j ++){
            for(k = j + 1; k <= j + 3 && k < len; k++){
                int num1, num2, num3, num4;
                char ch1[4] = {0}, ch2[4] = {0}, ch3[4] = {0}, ch4[4] = {0};
                for(l = 0; l <= i; l++){
                    ch1[l] = strCopy[l];
                }
                for(l = i + 1; l <= j; l++){
                    ch2[l - i - 1] = strCopy[l];
                }
                for(l = j + 1; j <= k; l++){
                    ch3[l - j - 1] = strCopy[l];
                }
                for(l = k + 1; l < len && len - 1 - k < 3; l++){
                    ch4[l - k - 1] = strCopy[l];
                }
                num1 = Char2Num(ch1);
                num2 = Char2Num(ch2);
                num3 = Char2Num(ch3);
                num4 = Char2Num(ch4);
                if(num1 && num2 && num3 && num4 && num1 <= 255 && num2 <= 255 && num3 <= 255&& num4 <= 255) 
                    cout << num1 <<':' << num2 << ':' << num3 << ':' << num4 << endl;
            }
        }
    }
    system("pause");
    return 0;
}
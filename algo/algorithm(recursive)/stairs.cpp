#include<iostream>
#define M 5001;
using namespace std; 
int a[5001][5001] = {0}, len = 1;
void carry_over(int n){
    int c = 0, i;
    for(i = 0; i < len; i++){
        a[n][i] = (a[n - 1][i] + a[n - 2][i] + c) % 10;
        c = (a[n - 1][i] + a[n - 2][i] + c) / 10;
    }
    if(c != 0){
        a[n][len++] = c % 10;
        c /= 10;
    } 
    /* for(i = 0; i < len; i++)
        a[n][i] = (a[n - 1][i] + a[n - 2][i]);
    for(i = 0; i < len; i++){
        if(a[n][i] >= 10){
            a[n][i + 1] += a[n][i] / 10;
            a[n][i] = a[n][i] % 10;
            if(a[n][len]) len++;
        }
    } */
}
int main(){
    int tar = 0, i;
    a[1][0] = 1; a[2][0] = 2;
    cin >> tar;

    for(i = 3; i <= tar; i++) carry_over(i);
    for(i = len - 1; i >= 0; i--) cout << a[tar][i];
    system("pause");
    return 0;
}

//log1 为什么原来的解法是错误的？？？？？？？
// 对进位理解还不够
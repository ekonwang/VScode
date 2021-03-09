#include<stdio.h>
#include<stdlib.h>
long switch_prob(long x, long n){
    long result = x;
    switch(n - 60){
        case 0:
        case 2:
            result = 8*x;           
            break;
        case 3:
            result = (x >> 3);
            break;
        case 4:
            result = (x << 4) - x;
        case 5:
            result *= result;
        default:
            result += 75;
    }
    return result;
} 
int main(){int res = switch_prob(2, 64); printf("%d", res); system("pause"); return 0;}
//关注函数原型，不要白做了题目没分数.
/* 本题应该使用dp解法，在之前问题的基础上解决下一个问题
    否则造成大量的冗余运算 
    //divide and conquer.*/
/* 尽量用优美的算法减少程序所需要的计算和判断 */
#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
ull c[25][25] = {0};
int jg[25][25] = {0};
int tx, ty, hx, hy;
const int ax[9] = {0, -2, -1, 2, 1, 2, 1, -2, -1};
const int ay[9] = {0, -1, -2, -1, -2, 1, 2, 1, 2};
void work(){
    int valA, valB, i, j;
    for(i = 0; i < 9; i++){
        jg[hx + ax[i]][hy + ay[i]] = 1;      //log1 低级错误，数组和变量重名
    }c[2][1] = 1;
    for(j = 2; j <= ty; j++){
        for(i = 2; i <= tx; i++){
            if(jg[i][j]) continue;
            c[i][j] = c[i-1][j] + c[i][j-1];
        }
    }
}
int main(){
    cin >> tx >> ty >> hx >> hy;
    tx += 2; ty += 2; hx += 2; hy += 2;
    work();
    cout << c[tx][ty];
    system("pause");
    return 0;
}









/* 错误解法 */
/* int hp(int i){if(i) return -1; else return 1;}
void preprocess(int hx, int hy){
    int t[4][2] = {0}; t[0][0] = t[0][1] = t[1][0] = t[2][1] = 1;
    int pos[8][2], i, j; 

    c[hx][hy] = 1;
    for(i = 0; i < 4; i++){
        for(j = 1; j <= 2; j++){
            pos[2 * i + j - 1][0] = hx + hp(t[i][0]) * j;
            pos[2 * i + j - 1][1] = hy + hp(t[i][1]) * (3 - j);
        }
    }
    for(i = 0; i < 8; i++){
        if(pos[i][0] <= 20 && pos[i][0] >= 0 && pos[i][1] <= 20 && pos[i][1] >= 0) 
            c[pos[i][0]][pos[i][1]] = 1;
    }
}
void process(int cx, int cy){
    if(c[cx][cy] == 1) {return;}
    else if(cx > tx || cy > ty) {return;}
    else if(cx == tx && cy == ty) {ans ++; return;}
    else{process(cx+1, cy);process(cx, cy+1);}
}
int main(){
    int hx, hy;
    cin >> tx >> ty >> hx >> hy;
    preprocess(hx, hy);
    process(0, 0);
    cout << ans << endl;
    system("pause");
    return 0;
}
 */
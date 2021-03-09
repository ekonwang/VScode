#include<string>
#include<iostream>
#include<vector>
using namespace std;
/* 关键词：回溯算法， 穷举思想 */
int res = -1, cres = 0;
int **matrix, *vis, *lengths;
void pre_procesor(vector<string> str_set){
    int num = str_set.size(); matrix = new int*[num];
    for(int i = 0; i < num; i++){
        matrix[i] = new int[num];
        for(int j = 0; j < num; j++){
            matrix[i][j] = 0;
            int len1 = str_set[i].length(), len2 = str_set[j].length();
            int len = len1 < len2? len1: len2;
            for(int k = 1; k < len; k++){
                if(str_set[i].substr(len1 -k, k) == str_set[j].substr(0, k)){ //忽略包含的情况
                    matrix[i][j] = k; break;
                }
            }
        }
    }
}
void dfs(int cur, int n){
    for(int i = 0; i < n; i++){
        if(!matrix[cur][i]) continue;
        if(vis[i] == 2) continue;
        vis[i]++;
        cres += lengths[i] - matrix[cur][i];
        dfs(i, n);
        vis[i]--;         //回溯
        cres -= lengths[i] - matrix[cur][i];
    }
    res = cres > res? cres : res;
}
int main(){
    int num; 
    vector<string> str_set; char prime;
    cin >> num; 
    vis = new int[num]; lengths = new int[num];
    for(int i = 0; i < num; i++){
        string str;
        cin >> str;
        str_set.push_back(str);
        vis[i] = 0; lengths[i] = str.length();
    }
    cin >> prime;
    pre_procesor(str_set);
    for(int i = 0; i < num; i++){         //有回溯步骤
        if (str_set[i][0] == prime){
            vis[i] ++;
            cres += lengths[i];
            dfs(i, num);
            vis[i] --;
            cres -= lengths[i];
        }
    } 
    cout << res;
    system("pause");
    return 0;
}
//log1 : no break; wrong answer 21, expected 23.
//log2 : try showing matrix, exception recurred.
//log3 : target founded: matrix defined second times.
//log3 : reason for wrong answer founded: cres not updated for the first time.


//idea: matrix multiply. graph theory. m[i, j](k)
/* int** multiply(int** matrix, int n, int times){
    int** res = new int*[n];
    for(int i = 0; i < n; i++){
        res[i] = new int[n];
        for(int j = 0; j < n; j++){
            res[i][j] = 0;
            if(i == j) res[i][i] = 1;
        }
    }
    for(int t = 0; t < times; t++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int value = 0;
                for(int k = 0; k < n; k++){
                    value += matrix[i][k]* res[k][j];
                }
                res[i][j] = value;
            }
        }
    }
    return res;
}
void show_matrix(int** matrix, int n){
    for(int i = 0; i < n; i++){
        cout << endl;
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << '\t';
        }
    }
    cout << endl << "------------------------------" << endl;
} */
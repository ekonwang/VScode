#include<iostream>
#include<algorithm>
#include<string>
#define N1 23
#define N2 11
typedef unsigned long long ull;
using namespace std;
struct db{
    ull x, y;
};
ull hash1_(string str){
    ull ans = 0;
    int len = str.length();
    for(int i = 0; i < len; i++) ans = (ans * N1) + str[i];
    return ans;
} 
ull hash2_(string str){
    ull ans = 0;
    int len = str.length();
    for(int i = len - 1; i > 0; i--) ans = (ans * N2) + str[i];
    return ans;
}
int cmp(db a, db b){
    return a.x < b.x;
}
int main(){
    db ary[10000];
    string str;
    int n, res = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        ary[i].x = hash1_(str);
        ary[i].y = hash2_(str);
    }
    sort(ary, ary + n, cmp);
    for(int i = 1; i < n; i++){
        if(ary[i].x != ary[i - 1].x || ary[i].y != ary[i - 1].y) res++;
    }
    cout << res << endl;
    //system("pause");
    return 0;
}

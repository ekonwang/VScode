#include<bits/stdc++.h>
using namespace std;
int a[16] = {0};
int pos = 15;
int pow(int x, int y){
    int res = 1;
    for(int i = 0; i < y; i++) res *= x;
    return res;
}
void swtch(int val){
    if(pos < 0) return;
    int up = pow(3, pos + 1)/2;
    int low = (pow(3, pos) + 1)/2;
    int cur = pow(3, pos);
    if(val <= up && val >= low){
        a[pos --] = 1;
        swtch(val - cur);
    }else if(val >= -up && val <= -low){
        a[pos --] = -1;
        swtch(val + cur);
    }else{
        pos --;
        swtch(val);
    }
}
int main(){
    int n;
    cin >> n;
    swtch(n);
    for(int i = 0; i < 16; i++) cout << a[i] << ' ';
    //system("pause");
    return 0;
}
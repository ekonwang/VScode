#include<iostream>
using namespace std;
char candidates[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
void switch_system(int n, int m){
    if(!n) return;
    int rem = n%m;
    if(rem < 0) {switch_system(n/m + 1, m); rem -= m;}
    else{switch_system(n/m, m);}
    cout << candidates[rem];
}
int main(){
    int n, m; cin >> n >> m;
    cout << n << '=';
    switch_system(n, m);
    cout << '(' << "base" << m << ')';
    //system("pause");
    return 0;
}
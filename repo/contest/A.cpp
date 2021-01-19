#include <iostream>
#define N 51
using namespace std;
double mypow(int n){
    double res = 1;
    for(int i = 0; i < n; i++){
        res *= 1.1;
    }
    return res;
}
double sol(int n){
    int corhigh = 2*n-11, corlow = 2*n-12;
    if(corhigh < 1){
        return n*200;
    }else if(corlow >= n){
        return n*100*mypow(n);
    }else{
        double tmp = mypow(corlow);
        double sollow = 100*(2*n - corlow)*tmp;
        double solhigh = 100*(2*n - corhigh)*tmp*1.1;
        if(sollow < solhigh) return solhigh;
        else return sollow;
    }
}
int main(){
    int n;
    cin >> n;
    cout << sol(n) << endl;
    //system("pause");
    return 0;
}
//vjudge 无法识别system("pause"); 会造成runtime error
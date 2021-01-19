#include<iostream>
using namespace std;
long upper(double value){
    if(value / (long)value == 1) return value;
    else return (long)value + 1;
}
int main(){
    long susceptibles, infectives, recovered = 0, n, new_recovered, new_infected;
    double infection_rate, recover_rate;
    cin >> susceptibles >> infectives >> n >> infection_rate >> recover_rate;
    for(int i = 0; i < n; i++){
        new_recovered = upper(infectives* recover_rate);
        new_infected = upper(infection_rate* infectives* susceptibles);
        recovered += new_recovered;
        infectives += new_infected;
        infectives -= new_recovered;
        susceptibles = susceptibles - new_infected;
        if (susceptibles < 0){
            infectives += susceptibles;
            susceptibles = 0;
        }
    } 
    cout << susceptibles << ' ' << infectives << ' ' << recovered;
    //system("pause");
    return 0;
}

//log1 类型转换：同样位长的数据，转换为第一个数据的数据类型
//log2 没有很好地考虑当新增感染人数大于剩余易感者的情况
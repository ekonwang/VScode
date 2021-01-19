#include<iostream>
using namespace std;
int main(){
    int days, *class_time, norm, addition, anger = 0, sum = 0;
    cin >> days;
    class_time = new int[days];
    for(int i = 0; i < days; i++){
        cin >> norm >> addition;
        class_time[i] = norm + addition;
    }
    for(int i = 0; i < days; i++){
        anger += (class_time[i] - 8);
        sum += anger;
    }
    cout << sum;
    //system("pause");
    return 0;
}
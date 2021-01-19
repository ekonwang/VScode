#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
double cubic_equation(double a, double b, double c, double d, double x){
    return pow(x, 3)*a + pow(x, 2)*b + x* c + d;
}
int main(){
    double a, b, c, d;
    int count = -100;
    cin >> a >> b >> c >> d;
    for(; count < 100; count ++){
        double mid;
        double left = (double) count;
        double right = (double) (count + 1);
        if(cubic_equation(a, b, c, d, left) == 0) {printf("%.2lf ", left); continue;}
        if(cubic_equation(a, b, c, d, left)* 
            cubic_equation(a, b, c, d, right) >= 0)
            continue;
        for(int i = 0; i < 10; i++){
            mid = (left + right)/2;
            double mid_result = cubic_equation(a, b, c, d, mid);
            double left_result = cubic_equation(a, b, c, d, left);
            //double right_result = cubic_equation(a, b, c, d, right);
            if(mid_result*left_result < 0) right = mid;
            else left = mid;  
        }
        printf("%.2lf ", left);
    }
    //system("pause");
    return 0;
}
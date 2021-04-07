#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define PI acos(-1)

int main() {
    int a = 1, b = 2;
    double t = a;
    t /= b;
    cout << setprecision(10) << t << endl;
    cout << setprecision(10) << (t = atan2(-1, -1)) << endl;
    cout << PI << endl;
    return 0;
}
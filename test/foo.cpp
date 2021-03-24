#include <iostream>
using namespace std;

void foo(int init=0)
{
    int a = 0x7fffffff;
    long long b = 0x7fffffff;
    b += a;
    cout << b << endl;
}

int main(){
    foo();
    return 0;
}
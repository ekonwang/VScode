#include <iostream>

void foo(int init=0)
{
    if(init >= 10) return;
    static int a = 1;
    std::cout << a << std::endl;
    foo(init + 1);
}
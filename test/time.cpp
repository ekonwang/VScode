#include<iostream>
#include<windows.h>
using namespace std;
int main(){ 
    DWORD64 s_time = GetTickCount();
    for(int i = 0; i < 1000000000; i++){}
    DWORD64 e_time = GetTickCount();
    cout << (e_time - s_time)/1000 << " s" << endl;
    system("pause");
    return 0;
}
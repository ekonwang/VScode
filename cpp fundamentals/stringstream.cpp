#include <string>
#include <iostream>
#include <sstream>
 
using namespace std;
 
int main()
{
    // 方法1
    int nNum1 = 123;
    stringstream ss;
    
    ss << nNum1;
    string strTest1 = ss.str();
    cout << "strTest1 is: " << strTest1 << endl;
    
    
    /* string strTest2;
    strTest2 << ss;     // stringstream 未定义 << 操作符，故此句报错
    cout << "strTest2 is: " << strTest2 << endl; */
    
 
    string strTest3;
    ss >> strTest3;
    cout << "strTest3 is: " << strTest3 << endl; 
 
    // 方法2
    int nNum2 = 456;
    string strTest4;
    strTest4 = to_string(nNum2);    // C++11 标准
    cout << "strTest4 is: " << strTest4 << endl;
    

    system("pause");
    return 0;
}
#include <iostream>    //cin、cout
#include <string>      //string
#include <stdio.h>     //freopen
#include <fstream>     //ifstream
#include <sstream>     //stringstream
using namespace std;
int main()  
{
    string str;
    int num;
    stringstream ss;

    FILE* fp;

    streambuf *backup;  
    ifstream fin;  
    fin.open("in.txt");  
    backup = cin.rdbuf();   // back up cin's streambuf  
    cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin  
    cin >> str;
    ss << str;
    ss >> num;
    // ... cin will read from file  
    cin.rdbuf(backup);     // restore cin's original streambuf 
    cout << num + 1 << endl; 


    /* why this block of code dont work as it supposed to be? */
/*     printf("This text is redirected to stdout\n");
    fp = freopen("file.txt", "r", stdin);
    cin >> str;
    fclose(fp);
    cout << str << '\n' << "input a string."; */


/*     string name, url;
    //将标准输入流重定向到 in.txt 文件
    fp = freopen("in.txt", "r", stdin);
    cin >> name >> url;
    fclose(fp);
    //将标准输出重定向到 out.txt文件
    fp = freopen("out.txt", "w", stdout); 
    cout << name << "\n" << url;
    fclose(fp); */
    system("pause");
    return 0;
}

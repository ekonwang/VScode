#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char univ[] = "Fudan ", name[10];
    int stuID = 12610, number, nRet = 0;
    char ch;
    ifstream inputFile;
    ofstream outputFile;
    outputFile.open("d:\\test.dat");
    outputFile << univ << endl;
    outputFile << stuID << endl;
    inputFile.open("d:\\test2.dat", ios::in|ios::_Nocreate);
    if(!inputFile){
        cerr << "can not open d:\\test1.dat" << endl;
        nRet = 1;
    }else{
        inputFile >> name >> ch >> name;
        outputFile << "name: " << name << endl;
        outputFile << "number: " << number << endl;
    }
    inputFile.close(); outputFile.close();
    system("pause");
    return 0;
}


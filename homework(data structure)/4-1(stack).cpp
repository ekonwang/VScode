#include<iostream>
using namespace std;
#include "mystack.h"

using namespace std;

int main(){
    int num, i, j, k, *Array, *ArrayB;
    cout << "input a number" << '\t';
    cin >> num;
    Array = new int[num];
    ArrayB = new int[num];
    mystack<int> s(num);

    for(i = 0; i < num; i++)
        cin >> Array[i] ;
    for(i = 0; i < num; i++)
        cin >> ArrayB[i] ;
    
    j = k = 0;
    while(j < num){
        if(Array[j] != ArrayB[k] && s.getTop() != ArrayB[k])
            s.push(Array[j++]);
        else{
            if(Array[j] == ArrayB[k]){
                j++;  
                k++;}               
            else {
                s.pop();
                k++;}
        }
    }
    int count = 0;
    while(!s.getTop()){
        int value;
        s.pop(value);
        if(value != Array[k++]) {
            count ++;
            break;
        }
    }
    if(!count) cout << "yes" << endl;
    else cout << "no" << endl;
    system("pause");
    return 0;
}



/*
#define MaxN 100

template<class T> class stack{
    T *s;
    int top;
public:
    stack():top(-1),s(new T[MaxN]){}; //constructor
    stack(int len):top(-1), s(new T[len]){};
    bool pop(){
        if (top == -1) return false;
        else top--; return true;
    }
    bool pop(T &receiver){
        if (top == -1) return false;
        else receiver = s[top--]; return true;
    }
    bool push(T &value){
        if (top == MaxN - 1) return false;
        else s[++top] = value;
    }
    T getTop(){
        if (top == -1) return NULL;
        return s[top--];
    }
    bool isEmpty(){
        if (top == -1) return true;
        else return false;
    }
};
*/

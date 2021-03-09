#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct node
{
    /* data */
    int data;
    node *lchild, *rchild;
    node(int val):data(val), lchild(NULL), rchild(NULL){};   //参数列表型构造函数应当在大括号后面加上分号
};

void preorder(node *& root){
    stack<node*> s;
    node * p = root;
    while(p != NULL || !s.empty()){
        while (p != NULL)
        {
            cout << p -> data << "\t";
            s.push(p);
            p = p -> lchild;
        }
        p = s.top();
        s.pop();
        p = p -> rchild;
    }
}
void midorder(node *& root){
    stack<node*> s;
    node * p = root;
    while(p != NULL || !s.empty()){
        while(p != NULL){
            s.push(p);
            p = p -> lchild;
        }
        p = s.top();
        cout << p -> data << "\t";
        s.pop();
        p = p -> rchild;
    }
}
void posorder(node *& root){
    stack<node*>v, s;
    node * p = root;
    while(p != NULL || !v.empty()){
        while(p != NULL){
            s.push(p); 
            v.push(p);
            p = p -> rchild;
        }
        p = v.top();
        v.pop();
        p = p -> lchild;
    }
    /* nodes' poiter stored reversely in stack s, just pop them in order is OK. */
    while(!s.empty()){
        p = s.top();
        s.pop();
        cout << p -> data << '\t';
    }
}
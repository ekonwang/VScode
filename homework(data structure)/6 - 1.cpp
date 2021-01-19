#include<iostream>
#include<string>
#include<vector>
using namespace std;
/* CreatBinTree 函数与非递归先根遍历preorder函数 */
template <class T> struct BinNode{
   T data;       
   BinNode <T> *lchild, *rchild; 
   BinNode(T value){data = value; lchild = NULL; rchild = NULL;}
};
/* 二叉树构造函数 to develop CreatBinTree(), define a function CreatBinTreeHelper, with recursive way */
void CreatBinTreeHelper(istream &in, BinNode<char>* &parent);
void CreatBinTree(istream &in, BinNode<char>* &BT){
    if(!in){BT = NULL; return;}
    char ch; in >> ch; BT -> data = ch; in >> ch;
    CreatBinTreeHelper(in, BT);    
}
/* 非递归先根遍历 pre-order travesal without recurive call */
void PreOrder(BinNode<char> *root){
    if (!root || !root -> data) return;
    vector<BinNode<char>*> vec;
    BinNode<char> *p = root;
    while(!vec.empty()||p != NULL){
        while(p != NULL){
            putchar(p -> data);
            vec.push_back(p);
            p = p -> lchild;
        }
        if(!vec.empty()){
            p = vec.back();
            vec.pop_back();
            p = p -> rchild;
        }
    }
    cout << endl;
}
int main(){
    /* test with main function. to test you can input string with spaces  
    example: A(a, b(c, d( e, f)))#
    input without '#' is permitted.
    */
    BinNode<char>* root = new BinNode<char>(NULL);
    CreatBinTree(cin, root);
    PreOrder(root);
    system("pause");
    return 0;
}










/* 
below: assistance functions 
*/
void CreatBinTreeHelper(istream &in, BinNode<char>* &parent){
    char ch;
    int flag = 0;
    BinNode<char>* child;
    while(in >> ch){
        switch(ch){
            case ',':
                flag ++;
                break;
            case ')':
                return;
            case ' ':
                break;
            case '(':               
                CreatBinTreeHelper(in, child);
                break;
            default:
                child = new BinNode<char>(ch);
                if(!flag) parent -> lchild = child;
                else parent -> rchild = child;
        }
    }
}

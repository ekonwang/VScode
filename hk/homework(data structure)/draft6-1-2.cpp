#include<iostream>
#include<string>
#include<vector>
using namespace std;
template <class T> struct BinNode{
   T data;       
   BinNode <T> *lchild, *rchild; 
   BinNode(T value){data = value; lchild = NULL; rchild = NULL;}
};
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
void CreatBinTree(istream &in, BinNode<char>* &BT){
    if(!in){BT = NULL; return;}
    char ch; in >> ch; BT -> data = ch; in >> ch;
    CreatBinTreeHelper(in, BT);    
}
void PreOrder1(BinNode<char>* root){
    if(root == NULL) return;
    putchar(root -> data);
    PreOrder1(root -> lchild);
    PreOrder1(root -> rchild);
}
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
    BinNode<char>* root = new BinNode<char>(NULL);
    CreatBinTree(cin, root);
    PreOrder(root);
    system("pause");
    return 0;
}
//log1: root野指针，赋值操作导致错误；
//log2：输入A(B(D,E(G,)),C(,F))#； preorder输出 A （
//log3: 同样的输入， preorder输出 A G  //新发现，break在递归前调用，重大错误； return可以结束switch语句，乃至整个函数 
//log4: 同样的输入, preorder输出 A C F
//log5: 输入A(a,b)，preorder输出 A b ;
//log6: 找到代码中出现的逻辑错误，本应该作为记录‘,’是否出现的flag在每次cin后重新赋值定义，导致flag失效，今后在循环中声明赋值变量要注意
//成功输出结果
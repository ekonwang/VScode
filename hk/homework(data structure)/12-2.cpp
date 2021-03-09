#include<iostream>
#include<algorithm>
#define N 6
using namespace std;
struct AVLnode{
    int data = 0, bf = 0, height = 0;
    AVLnode *lchild = NULL, *rchild = NULL;
    AVLnode(int val){data = val;}
};
int getHeight(AVLnode* &p){
    if(p == NULL) return -1; else return p -> height;
}
void getBF(AVLnode* &root){
    int hl = 0, hr = 0;
    hl = getHeight(root -> lchild);
    hr = getHeight(root -> rchild);
    root -> height = max(hl, hr) + 1;
    root -> bf = hl - hr;
}
void rotateL(AVLnode*& p){
    AVLnode* pleft = p;
    p = p -> rchild;
    pleft -> rchild = p -> lchild;
    p -> lchild = pleft;
    getBF(pleft);
    getBF(p);
}
void rotateR(AVLnode* &p){
    AVLnode* pright = p;
    p = p -> lchild;
    pright -> lchild = p -> rchild;
    p -> rchild = pright;
    getBF(pright);
    getBF(p);
}
void rotateLR(AVLnode* &p){
    rotateL(p -> lchild);       //不能使用中间变量，否则不会改变lchild指针的值！！！
    rotateR(p);
}
void rotateRL(AVLnode* &p){
    rotateR(p -> rchild);      //不能使用中间变量，否则不会改变rchild指针的值！！！
    rotateL(p);
}
void AVL_insert(AVLnode* &root, int val){
    if(root == NULL){
        root = new AVLnode(val);
        return;
    }
    if(val <= root -> data){
        AVL_insert(root -> lchild, val);     //使用指针引用的好处
        getBF(root);
        if(root -> bf > 1){
            if(root -> lchild -> data >= val){
                rotateR(root);               //使用指针的引用
            }else{
                rotateLR(root);
            }
        }
    }else{
        AVL_insert(root -> rchild, val);
        getBF(root);
        if(root -> bf < -1){
            if(root -> rchild -> data < val){
                rotateL(root);
            }else{
                rotateRL(root);
            }
        }
    }
}
void midorder(AVLnode *&root){
    if(root == NULL) return;
    midorder(root -> lchild);
    cout << root -> data << " ";
    midorder(root -> rchild); 
}
int main(){
    AVLnode *root = NULL;
    int a[N] = {1, 8, 2, 6, 5, 4};
    for(int i = 0; i < N; i++){
        AVL_insert(root, a[i]);
    }
    midorder(root);
    system("pause");
    return 0;
}
#include<iostream>
using namespace std;
struct AVLnode{
    int data = 0, bf = 0;
    AVLnode* parent = NULL, *lchild = NULL, *rchild = NULL;
    AVLnode(int val){data = val;}
};
void rotateL(AVLnode*& p){
    AVLnode* pleft = p;
    p = p -> rchild;
    pleft -> rchild = p -> lchild;
    p -> lchild = pleft;
    
    pleft -> rchild -> parent = pleft;
    p -> parent = pleft -> parent;
    pleft -> parent = p;   
}
void rotateR(AVLnode* &p){
    AVLnode* pright = p;
    p = p -> lchild;
    pright -> lchild = p -> rchild;
    p -> rchild = pright;

    pright -> lchild -> parent = pright;
    p -> parent = pright -> parent;
    pright -> parent = p;
}
void rotate_LR(AVLnode* &p){
    AVLnode* pleft = p -> lchild;
    rotateL(pleft);
    rotateR(p);
}
void rotate_RL(AVLnode* &p){
    AVLnode* pright = p -> rchild;
    rotateR(pright);
    rotateL(p);
}

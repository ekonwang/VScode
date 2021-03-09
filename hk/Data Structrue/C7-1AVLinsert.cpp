#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct AVLnode{
    int data, bf, height;
    AVLnode * lchild, * rchild;
    AVLnode(int val){
        bf = height = 0;
        data = val;
        lchild = rchild = NULL;
    }
};
int getHeight(AVLnode *& p){
    if(!p) return -1;
    else return p -> height;
}
void reBF(AVLnode *& p){
    int hl = getHeight(p -> lchild);
    int hr = getHeight(p -> rchild);
    p -> height = max(hl, hr) + 1;             //remember to add 1.
    p -> bf = hl - hr;
}
void rotateL(AVLnode *& root){
    AVLnode * rootLeft = root;
    root = root -> rchild;
    rootLeft -> rchild = root -> lchild;
    root -> lchild = rootLeft;
    reBF(rootLeft);
    reBF(root);
}
void rotateR(AVLnode *& root){
    AVLnode * rootRight = root;
    root = root -> lchild;
    rootRight -> lchild = root -> rchild;
    root -> rchild = rootRight;
    reBF(rootRight);
    reBF(root);
}
void rotateRL(AVLnode *& root){
    rotateR(root -> rchild);
    rotateL(root);
}
void rotateLR(AVLnode *& root){
    rotateL(root -> lchild);
    rotateR(root);
}
void insert(int val, AVLnode *& root){          //insert recursively.
    if(!root) {
        root = new AVLnode(val);
    }
    if(val <= root -> data){
        insert(val, root -> lchild);
        reBF(root);
        if(root -> bf > 1){
            if(val <= root -> lchild -> data){
                rotateR(root);
            }else rotateLR(root);
        }
    }else{
        insert(val, root -> rchild);
        reBF(root);
        if(root -> bf < -1){
            if(val > root -> rchild -> data){
                rotateL(root);
            }else rotateRL(root);
        }
    }
}
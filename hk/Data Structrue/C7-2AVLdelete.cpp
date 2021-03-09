#include <iostream>
#include <vector>
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
    p -> height = max(hl, hr) + 1;                      //remember to add 1.
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
void getRM(AVLnode *& root, AVLnode *& p){
    p = root -> rchild;
    if(p) while(p -> lchild) p = p -> lchild;
}
void getLM(AVLnode *& root, AVLnode *& p){
    p = root -> lchild;
    if(p) while(p -> rchild) p = p -> rchild;
}
bool Delete(AVLnode *& root, int val){
    if(!root) {
        cout << "value " << val << " : no found." << endl;
        return false;
    }
    if(root -> data == val){
        AVLnode * t = root;
        if(!root -> lchild || !root -> rchild){
            root = root -> lchild ? root -> lchild : root -> rchild;
            delete t;
        }else{
            if(getHeight(root -> lchild) >= getHeight(root -> rchild)){
                getLM(root, t);
                root -> data = t -> data;
                t -> data = val;
                Delete(root -> lchild, val);
            }else{
                getRM(root, t);
                root -> data = t -> data;
                t -> data = val;
                Delete(root -> rchild, val);
            }
        }
    }else if(val < root -> data){
        if( !Delete(root -> lchild, val) ) return false;
        reBF(root);
        if(root -> bf < -1){
            AVLnode * t = root -> rchild; 
            if(getHeight(t -> lchild) <= getHeight(t -> rchild)){
                rotateL(root);
            }else rotateRL(root);
        }
    }else{
        if( Delete(root -> rchild, val) ) return false;
        reBF(root);
        if(root -> bf > 1){
            AVLnode * t = root -> lchild;
            if(getHeight(t -> lchild) >= getHeight(t -> rchild)){
                rotateR(root);
            }else rotateLR(root);
        }
    }
}

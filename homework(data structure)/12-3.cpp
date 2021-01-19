#include<iostream>
#include<algorithm>
#define N 15
using namespace std;
struct AVLnode{
    int data = 0, bf = 0, height = 0;
    AVLnode *lchild = NULL, *rchild = NULL;
    AVLnode(int val){data = val;}
};

int getHeight(AVLnode* &root);
void midorder(AVLnode *&root);
void getBF(AVLnode* &root);
void rotateR(AVLnode* &root);
void rotateL(AVLnode* &root);
void rotateLR(AVLnode* &root);
void rotateRL(AVLnode* &root);
void getLM(AVLnode* &root, AVLnode* &p);
void getRM(AVLnode* &root, AVLnode* &p);
void AVL_insert(AVLnode* &root, int val){
    if(root == NULL){
        root = new AVLnode(val);
        return;
    }
    if(val <= root -> data){
        AVL_insert(root -> lchild, val);     //using refrence of pointer simpfies the process
        getBF(root);
        if(root -> bf > 1){
            if(root -> lchild -> data >= val){
                rotateR(root);               //using refrence of pointer
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
bool AVL_delete(AVLnode* &root, int val){
    if(root == NULL) {cout << "Value " << val << " : No Found." << endl; return false;}
    if(root -> data == val){
        AVLnode* t = root;
        if(root -> lchild != NULL && root -> rchild != NULL){
            if(getHeight(root -> lchild) > getHeight(root -> rchild)){
                getLM(root, t);
                root -> data = t -> data;
                AVL_delete(root -> lchild, t -> data);
            }else{
                getRM(root, t);
                root -> data = t -> data;
                AVL_delete(root -> rchild, t -> data);
            }
        }else{
            root = root -> rchild? root -> rchild : root -> lchild;
            delete t;
        }
    }
    else if(val < root -> data){
        if(!AVL_delete(root -> lchild, val)) return false;
        getBF(root);
        if(root -> bf < -1){
            AVLnode* t = root -> rchild;
            if(getHeight(t -> lchild) > getHeight(t -> rchild)){
                rotateRL(root);
            }else rotateL(root);
        }
    }else if(val > root -> data){
        if(!AVL_delete(root -> rchild, val)) return false;
        getBF(root);
        if(root -> bf > 1){
            AVLnode* t = root -> lchild;
            if(getHeight(t -> rchild) > getHeight(t -> lchild)){
                rotateLR(root);
            }else rotateR(root);
        }
    }
    return true;
}

int main(){
    AVLnode* root = NULL;
    int a[N] = {1, 3, 5, 7, 9, 0, 11, 13, 14, 12, 2, 4, 6, 8, 10};
    for(int i = 0; i < N; i++) AVL_insert(root, a[i]);
    midorder(root); cout << endl;

    AVL_delete(root, 1);
    midorder(root); cout << endl;

    AVL_delete(root, 12);
    midorder(root); cout << endl;
    
    AVL_delete(root, 21);
    midorder(root); cout << endl;

    AVL_delete(root, -1);
    midorder(root); cout << endl;

    system("pause");
    return 0;
}


















/* assistance functions */
int getHeight(AVLnode* &root){
    if(root == NULL) return -1; else return root -> height;
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
    rotateL(p -> lchild);       //p是引用型变量而非拷贝型变量，使用中间变量将使得lchild不被改变
    rotateR(p);
}
void rotateRL(AVLnode* &p){
    rotateR(p -> rchild);      //不能使用中间变量，否则不会改变rchild指针的值！！！
    rotateL(p);
}
void getLM(AVLnode* &root, AVLnode* &p){       //获取左子树最大节点
    p = root -> lchild;
    while(p -> rchild) p = p -> rchild;
}
void getRM(AVLnode* &root, AVLnode* &p){       //获取右子树最小节点
    p = root -> rchild;
    while(p -> lchild) p = p -> lchild;
}
void midorder(AVLnode *&root){
    if(root == NULL) return;
    midorder(root -> lchild);
    cout << root -> data << " ";
    midorder(root -> rchild); 
}
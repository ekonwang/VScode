//log1 next函数 while(p -> lchld != NULL) 应该为 while(p -> ltag == 0 && p -> lchild != NULL)
//log2 creat_tree中寻找 p 也是同样的错误，要时刻意识到线索树中除了首末节点，其他节点的左右孩子都是
//一定存在的，所以要结合tag判断#include<bits/stdc++.h>
#ifndef tree_creation_h
#define tree_creation_h

#include "Bitnode.h"
#include <iostream>
#include <vector>
using namespace std;
//AVL树的构建
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
//线索二叉搜索树
snode* Create_thread_search_tree(snode*& root, int a[], int n){   
    int pos = 0, cur = 0;
    root = new snode(a[pos++]);
    snode *p, *q, *head = root;

    for(; pos < n; pos++){
        p = root;
        q = new snode(a[pos]);
        cur = a[pos];
        while(1){
            if(cur <= p -> data){
                if(p -> lchild != NULL && p -> ltag == 0) p = p -> lchild;
                else break;
            }
            else{
                if(p -> rchild != NULL && p -> rtag == 0) p = p -> rchild;
                else break;
            }
        }
        if(q -> data <= p -> data){
            q -> lchild = p -> lchild;
            q -> ltag = p -> ltag;
            q -> rchild = p;
            q -> rtag = 1;
            p -> lchild = q;
            p -> ltag = 0;
            if(q -> lchild == NULL) head = q;
        }else{
            q -> rchild = p -> rchild;
            q -> rtag = p -> rtag;
            q -> lchild = p;
            q -> ltag = 1;
            p -> rchild = q;
            p -> rtag;
        }
    }
    return head;
}
//二叉搜索树
void create_search_tree(node*& root, string str){  
    int pos = 1, cur = 0, len = str.length();
    cur = str[0] - '0';
    root = new node(cur);
    node *p, *q;
    for(; pos < len; pos++){
        p = root;
        cur = str[pos] - '0';
        q = new node(cur);
        while(1){
            if(cur < p -> data){
                if(p -> lchild != NULL) p = p -> lchild;
                else break;
            }
            else{
                if(p -> rchild != NULL) p = p -> rchild;
                else break;
            }
        }
        if(cur < p -> data){
            p -> lchild = q;
        }else{
            p -> rchild = q;
        }
    }
}
// creat the tree in level
vector<int> ns;
node* creat_tree(vector<int> ns)  
{
    int i, pos = 1, len = ns.size();
    node* root = new node(ns[0]), *p = root;
    vector<node*> nods; nods.push_back(p); 
    while(1){
        for(i = 0; i < nods.size(); i++){
            if(ns[pos] != -1){
                p = new node(ns[pos++]);
                nods[i] -> lchild = p;
                nods.push_back(p);
                
            }else pos++;
            if(pos == len) break;
            if(ns[pos] != -1){
                p = new node(ns[pos++]);
                nods[i] -> rchild = p;
                nods.push_back(p);
            }else pos++;
            if(pos == len) break;
        }
        if(pos == len) break;
        nods.erase(nods.begin(), nods.begin() + i);
    }
    return root;
}

#endif
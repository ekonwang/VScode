#ifndef Bitnode_H
#define Bitnode_H
#include<iostream>

struct node{
    int data;
    node* lchild, *rchild;
    node(int val){data = val; lchild = rchild = NULL; }
};
struct snode{
    int data, ltag = 0, rtag = 0;
    snode* lchild, *rchild;
    snode(int val){data = val; lchild = rchild = NULL;}
};
struct AVLnode{
    int data = 0, bf = 0, height = 0;
    AVLnode *lchild = NULL, *rchild = NULL;
    AVLnode(int val){data = val;}
};
template<class DataType> struct tnode{
    DataType data;
    tnode<DataType>* lchild, *rchild;
    tnode<DataType>(DataType val){data = val; lchild = rchild = NULL;}
};


#endif
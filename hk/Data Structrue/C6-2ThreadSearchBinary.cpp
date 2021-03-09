#include <iostream>
using namespace std;
struct NODE{
    char data;
    int ltag, rtag;
    NODE * lchild, * rchild;
    NODE(int val):data(val), ltag(0), rtag(0), lchild(NULL), rchild(NULL) {};
};
NODE* thread_sort_tree(char a[], int n){
    NODE * root, * head, * p, * r;
    int i;
    if(!n) return NULL;
    root = (NODE *) malloc(sizeof(NODE));
    root -> data = a[0];
    root -> lchild == NULL ;
    root -> ltag = 0;
    root -> rtag = 0;
    head = root;
    for(i = 1; i < n; i++)
    {
        r = (NODE * )malloc(sizeof(NODE));
        r -> data = a[i];
        p = root;
        while(1){
            if(r -> data <= p -> data)
                if(p -> rtag == 0 && p -> lchild != NULL) p = p -> lchild;
                else break;
            else if(p -> rtag == 0 && p -> rchild != NULL) p = p -> rchild;
                else break;
        }
        if(r -> data < p -> data)
        {
            r -> lchild = p -> lchild;
            r -> ltag = p -> ltag;
            r -> rchild = p;
            r -> rtag = 1;
            p -> lchild;
            p -> ltag = 0;
            if(r -> lchild == NULL) head = r;
        }
        else if(r -> data > p -> data){
            r -> rchild = p -> rchild;
            r -> rtag = p -> rtag;
            r -> lchild = p;
            r -> ltag = 1;
            p -> rchild = r;
            p -> rtag = 0;
        }
    }
    return head;
}
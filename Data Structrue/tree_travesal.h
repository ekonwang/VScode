#ifndef tree_travesal_h
#define tree_travesal_h

#include <iostream>
#include "Bitnode.h"
using namespace std;
/* level travesal for normal tree */

/* midorder for normal tree, using a recursive way*/
void midorder(node *&root){
    if(root == NULL) return;
    midorder(root -> lchild);
    cout << root -> data << " ";
    midorder(root -> rchild); 
}

/* midorder for AVLtree */
void midorder(AVLnode *&root){
    if(root == NULL) return;
    midorder(root -> lchild);
    cout << root -> data << " ";
    midorder(root -> rchild); 
}

/* midorder travesal for thread tree */
snode* next(snode *p){
    if(p -> rtag == 1) return p -> rchild;
    else{
        p = p -> rchild;
        if(p != NULL){
            while( p -> ltag == 0 && p -> lchild != NULL) p = p -> lchild;  
        }
        return p;
    }
}
/* midorder travesal for thread tree */
void midorder(snode* head){
    snode* p;
    for(p = head; p != NULL; p = next(p)) 
        cout << p -> data << ' ';
}

#endif
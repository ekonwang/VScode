#include<bits/stdc++.h>
using namespace std;
typedef struct BitNode{
    char data;
    struct BitNode* lchild, *rchild;
    int ltag, rtag;
};
BitNode* next(BitNode* cur){
    if(cur == NULL) return NULL;
    if(cur -> rtag) return cur -> rchild;
    else {
        if(cur -> rchild == NULL) return NULL;
        else{
            cur = cur -> rchild;
            while(cur -> ltag == 0){
                cur = cur -> lchild;
            }
        } 
    }
}

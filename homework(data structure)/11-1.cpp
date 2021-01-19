#include<iostream>
using namespace std;
struct snode{
    int data, ltag = 0, rtag = 0;
    snode* lchild, *rchild;
    snode(int val){data = val; lchild = rchild = NULL;}
};
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
void midorder(snode* head){
    snode* p;
    for(p = head; p != NULL; p = next(p)) 
        cout << p -> data << ' ';
}
int main(){
    int n = 0, i = 0, val, *a;
    snode* root, *head;
    cin >> n;
    a = new int[n];
    for(i = 0; i < n; i++){
        cin >> val;
        a[i] = val;
    }
    head = Create_thread_search_tree(root, a, n);
    midorder(head);
    system("pause");
    return 0;
}
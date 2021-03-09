#include <iostream>
#include <algorithm>
#include <string>
#define Max 100
using namespace std;
struct node{
    int data, height;
    node* lchild, *rchild, *parent;
    node(int val){data = val; height = 0; parent = lchild = rchild = NULL; }
};
int flag = 0;  // 判断是否为AVL树的变量
    node* nodes[Max];
void create_tree(node*& root){
    int n = 0, val = 0, i = 0, j = 0, valA = 0, valB = 0;
    string cA, cB;
    node* p;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val;
        nodes[i] = new node(val);
    }
    for(int j = 1; j <= n; j++){
        cin >> cA >> cB;
        if( cA.length() != 1 || cA[0] != '-'){
            valA = stoi(cA);
            nodes[j] -> lchild = nodes[valA];
            nodes[valA] -> parent = nodes[j];
        }
        if(cB.length() != 1 || cB[0] != '-'){
            valB = stoi(cB);
            nodes[j] -> rchild = nodes[valB];
            nodes[valB] -> parent = nodes[j];
        }
    }
    p = nodes[1];
    while(p -> parent != NULL){
        p = p -> parent;
    }
    root = p;
}
int getHeight(node* &p){
    if(p == NULL) return -1; else return p -> height;
}
int bf(node* root){
    int hl = 0, hr = 0;
    hl = getHeight(root -> lchild);
    hr = getHeight(root -> rchild);
    root -> height = max(hl, hr) + 1;
    return hl - hr;
}
void judge(node *root){
    if(root == NULL) return;
    int BF_val;
    judge(root -> lchild);
    judge(root -> rchild);
    BF_val = bf(root);
    if(BF_val > 1 || BF_val < -1) flag = 1;
}
int main(){
    node* root;
    create_tree(root);
    judge(root);
    if(flag) cout << "NO" << endl;
    else cout << "YES" << endl;
    //system("pause");
    return 0;
}

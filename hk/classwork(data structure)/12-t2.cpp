#include<iostream>
#include<string>
#define N 10
using namespace std;
struct node{
    int data, height;
    node* lchild, *rchild, *parent;
    node(int val){data = val; height = 0; parent = lchild = rchild = NULL; }
};
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
bool flag = true;
void cmp(node* rootA, node* rootB){
    if(rootA == NULL || rootB == NULL){
        if(rootB != NULL || rootA != NULL) flag = false;
        return;
    }
    if(rootA -> data != rootB -> data) flag = false;
    cmp(rootA -> lchild, rootB -> lchild);
    cmp(rootA -> rchild, rootB -> rchild);
}
int main(){
    string origin, test;
    node* rootA, *rootB;
    int n = 0;
    while(cin >> n){
        if(n == 0) break;
        cin >> origin;
        create_search_tree(rootA, origin);
        for(int i = 0; i < n; i ++){
            cin >> test;
            create_search_tree(rootB, test);
            flag = true;
            cmp(rootA, rootB);
            if(flag == true)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    //system("pause");
    return 0;
}

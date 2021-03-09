#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct node{
    char data;
    node* lchild, *rchild;
    node(){lchild = NULL; rchild = NULL;}
};
int intcase(string str, int n){
    int count0 = 0, count1 = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '0') count0++;
        else count1++;
        if(count1 && count0) return 2;
    }
    if(!count1) return 0;
    return 1;
}
void FDU_tree(string str, node* root){
    int len = str.length();
    if(len == 1) {
        if(str[0] == '0') root -> data = 'F';
        else root -> data = 'D';
        return;
    }
    string sub1_str = str.substr(0, len/2), sub2_str = str.substr(len/2, len/2);
    root -> lchild = new node(); root -> rchild = new node();
    int num = intcase(str, len);
    if(num == 0) root -> data = 'F';
    else if (num == 1) root -> data = 'D';
    else root -> data = 'U';
    FDU_tree(sub1_str, root -> lchild);
    FDU_tree(sub2_str, root -> rchild);
}
void pos(node* root){
    if(root == NULL) return;
    pos(root -> lchild);
    pos(root -> rchild);
    cout << root -> data;
}
int main(){
    int value;
    string str;
    node* root = new node();
    cin >> value;
    cin >> str;
    FDU_tree(str, root);
    pos(root);
    //system("pause");
    return 0;
}
//log1 exception
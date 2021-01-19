#include<iostream>
#include<string>
using namespace std;
struct node{
    char data;
    node* lchild , *rchild;
    node(char v){data = v; lchild = rchild = NULL;}
};
int fl = 0;
void creat(node* &root, string str1, string str2, int f = 1){
    if(!str1.length()){
        return;
    }else if(str1.length() == 1) {
        root = new node(str1[0]);
        fl = f > fl? f : fl;
        return;
    }
    int sub = f + 1;
    char ch = str1[0];
    int len = str1.length(), pos;
    root = new node(ch);
    for(int i = 0; i < len; i++){
        if(str2[i] == ch){
            pos = i;
            break;
        }
    }
    creat(root -> lchild, str1.substr(1, pos), str2.substr(0, pos), sub);
    creat(root -> rchild, str1.substr(pos + 1, len - pos - 1), str2.substr(pos + 1, len - pos - 1), sub);
}
void travesal(node* root){
    if(root == NULL) return;
    cout << root -> data << endl;
    travesal(root -> lchild);
    travesal(root -> rchild);
}
int main(){
    int n;
    string str1, str2;
    node* root;
    cin >> n >> str1 >> str2;
    creat(root, str1, str2);
    cout << fl;
    system("pause");
    cin >> n;
    return 0;
}
//log1 (creat)忽略情况str.length() == 0

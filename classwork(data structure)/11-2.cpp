#include<iostream>
#include<vector>
#define MaxN 100
using namespace std;
struct node{
    int data;
    node* lchild, *rchild;
    node(int v){
        data = v;
        lchild = rchild = NULL;  //什么时候可以用
    }
};
int a[MaxN] = {0}, b[MaxN] = {0};
void creat_tree(node *&root, int start, int start2, int len){
    if(len == 0) return;

    int r = a[start];
    root = new node(r);

    if(len == 1) root -> data = a[start];
    int sublen = 0, i = 0;
    for(i = start2; i < start2 + len; i++){
        if(b[i] == r) break;
    }
    sublen = i - start2;

    creat_tree(root -> lchild, start + 1, start2, sublen);
    creat_tree(root -> rchild, start + sublen + 1, i + 1, len - sublen - 1);
}
void Delete(node *& root, int val){
    if (!root || !root -> data) return;
    int flag = 0;
    vector<node*> vec;
    node *p = root, *res = NULL, *parent = NULL;
    while(!vec.empty()||p != NULL){
        while(p != NULL){
            if(p -> data == val) res = p;
            vec.push_back(p);
            p = p -> lchild;
        }
        if(!vec.empty()){
            p = vec.back();
            vec.pop_back();
            p = p -> rchild;
        }
    }
    vec.clear();
    p = root;
    while(!vec.empty()||p != NULL){
        while(p != NULL){
            if(p -> lchild == res || p -> rchild == res){
                parent = p;
                if(p -> lchild == res) flag = 1;
                else flag = 2;
            }
            vec.push_back(p);
            p = p -> lchild;
        }
        if(!vec.empty()){
            p = vec.back();
            vec.pop_back();
            p = p -> rchild;
        }
    }
    if(res != NULL){
        if(!flag) root = root -> rchild;
        else if(flag == 1){
            parent -> lchild = res -> rchild;
        }else{
            root = res -> rchild;
        }
    }
}
void Level_travesal(node* root){
    int len = 0, i = 0, flag = 0, pos = 0;
    vector<node*> vec; vec.push_back(root); 
    vector<int> nums;
    node* p = root;
    while(true){
        len = vec.size();
        flag = 0;
        for(i = 0; i < len; i++){
            p = vec[i];
            if(p != NULL){
                nums.push_back(p -> data);
                vec.push_back(p -> lchild);
                vec.push_back(p -> rchild);
                if(p -> lchild != NULL || p -> rchild != NULL) flag ++;
            }else{
                nums.push_back(-1);
            }
        }
        if(!flag) break;
        vec.erase(vec.begin(), vec.begin() + len);
    }
    pos = nums.size() - 1;
    while(nums[pos] == -1) pos--;
    for(i = 0; i <= pos; i++) cout << nums[i] << ' ';
}
int main(){
    int val, i = 0, len = 0, pop = -1;
    vector<int> v;
    node* root;

    while(cin >> val){
        a[len++] = val;
        if(cin.get() == '\n') break;
    }
    for(i = 0; i < len; i++){
        cin >> val;
        b[i] = val;
    }
    cin >> pop;

    creat_tree(root, 0, 0, len);
    Delete(root, pop);
    Level_travesal(root);
    //system("pause");
    return 0;
}

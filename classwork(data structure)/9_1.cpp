#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node* lchild, *rchild;
    node(int v){
        data = v;
        lchild = rchild = NULL;  //什么时候可以用
    }
};
node* creat_tree(vector<int> ns){
    int i, pos = 1, len = ns.size();
    node* root = new node(ns[0]), *p = root;
    vector<node*> nods; nods.push_back(p); 
    while(1){
        for(i = 0; i < nods.size(); i++){
            if(ns[pos] != -1){
                p = new node(ns[pos++]);
                nods[i] -> lchild = p;
                nods.push_back(p);
                
            }else pos++;
            if(ns[pos] != -1){
                p = new node(ns[pos++]);
                nods[i] -> rchild = p;
                nods.push_back(p);
            }else pos++;
            if(pos == len) break;
        }
        if(pos == len) break;
        nods.erase(nods.begin(), nods.begin() + i);
    }
    return root;
}
int is_son(node* cur, int tar){
    if(cur == NULL) return 0;
    if(cur -> data == tar) return 3;
    else{
        if(is_son(cur -> lchild, tar)) return 1;
        else if(is_son(cur -> rchild, tar)) return 2;
        else return 0;
    }
}
int find_common(node* root, int s, int t){
    node* p = root;
    int t1 = is_son(p, s), t2 = is_son(p, t);
    while(p != NULL){
        if(t1 != t2) return p -> data;
        else if(t1 == 1) p = p -> lchild;
        else p = p -> rchild;
        t1 = is_son(p, s);
        t2 = is_son(p, t);
    }
    return -1;
}
int main(){
    vector<int> ns;
    int v, t, s, res;
    node* root;
    while(cin >> v){
        ns.push_back(v);
        if (cin.get() == '\n') break;
    }
    root = creat_tree(ns);

    /* cout << is_son(root, 4) << endl;
    cout << is_son(root, 5) << endl;
    cout << is_son(root -> lchild, 0) << endl;
    cout << is_son(root -> rchild -> lchild, 0) << endl; */

    cin >> t >> s; 
    res = find_common(root, t, s);
    cout << res << endl;
    system("pause");
    return 0;
}
//log1 creattree 没有入栈
//log2 find_common 没有入栈
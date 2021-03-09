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
struct result{
    int x, y, gap;
    result(int a, int b, int g){
        if(a <= b){
            x = a;  y = b; 
        }else{
            y = a;  x = b; 
        }
        gap = g;
    }
};
int M = 999;
vector<result> R;

node* creat_tree(vector<int> ns)  // creat the tree in level
{
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
            if(pos == len) break;
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
void find_least_gap(node* root){
    if(root == NULL) return;

    int lflag = 0, rflag = 0, t1, t2, t3, res;
    node* p = root -> lchild, *q = root -> rchild;
    if(p != NULL) lflag ++;
    if(q != NULL) rflag ++; 
    while(lflag && p -> rchild != NULL){
        p = p -> rchild;
    }
    while(rflag && q -> lchild != NULL){
        q = q -> lchild;
    }
    t1 = root -> data;
    if(lflag){
        t2 = p -> data;
        res = t1 > t2 ? (t1 - t2):(t2 - t1);
        M = res < M? res : M;
    }
    if(rflag){
        t3 = q -> data;
        res = t1 > t3 ? (t1 - t3):(t3 - t1);
        M = res < M? res: M;
    }

    find_least_gap(root -> lchild);
    find_least_gap(root -> rchild);
}
void fit(node* root){
    if(root == NULL) return;
    int lflag = 0, rflag = 0, t1, t2, t3, lev1 = 1, lev2 = 1, res;
    node* p = root -> lchild, *q = root -> rchild;
    if(p != NULL) lflag ++;
    if(q != NULL) rflag ++; 
    while(lflag && p -> rchild != NULL){
        p = p -> rchild;
        lev1 ++;
    }
    while(rflag && q -> lchild != NULL){
        q = q -> lchild;
        lev2++;
    }
    t1 = root -> data;
    if(lflag){
        t2 = p -> data;
        res = t1 > t2 ? (t1 - t2):(t2 - t1);
        if (res == M) {
            result r1(t1, t2, lev1);
            R.push_back(r1);
        }
    }
    if(rflag){
        t3 = q -> data;
        res = t1 > t3 ? (t1 - t3):(t3 - t1);
        if(res == M){
            result r2(t1, t3, lev2);
            R.push_back(r2);
        }
    }
    fit(root -> lchild);
    fit(root -> rchild);
}
void ans(){
    int len = R.size(), i = 0, m = -1;

    for(i = 0; i < len; i++) {
        m = m > R[i].gap ? m : R[i].gap;
    }
    for(i = 0; i < len; i++){
        if(m == R[i].gap){
            cout << R[i].x << " " << R[i].y << endl;
        }
    }
}
int main(){
    int val;
    node* p;
    vector<int> numbers;

    while(cin >> val){
        numbers.push_back(val);
        if(cin.get() == '\n') break;
    }
    p = creat_tree(numbers);
    find_least_gap(p);
    fit(p);
    ans();
    //system("pause");
    return 0;
}




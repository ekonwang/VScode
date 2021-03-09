#include<iostream>
#include<vector>
using namespace std;
/* definition of BiTNode in required format */
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
    BiTNode(char value){
        data = value;
        lchild = NULL; rchild = NULL;
    }
};
/* 寻找两个节点共同祖先函数
   function getLCA.  develop getLCA with assitance from PreOrderSearchValue  *
   PreOrderSearchValue is designed to find node with specified value, travesal in pre-order way */
bool PreOrderSearchValue(BiTNode* ancester, char value);
BiTNode* getLCA(BiTNode* root, char X, char Y){
    vector<BiTNode*> vec;
    BiTNode *p = root;
    while(!vec.empty()||p != NULL){
        while(p != NULL){
            if(PreOrderSearchValue(p, X) && PreOrderSearchValue(p, Y)){
                if((!PreOrderSearchValue(p -> lchild, X)||
                    !PreOrderSearchValue(p -> lchild, Y))&&
                    (!PreOrderSearchValue(p -> rchild, X)||
                    !PreOrderSearchValue(p -> rchild, Y)))
                    return p;
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
    return NULL;
}
/*  寻找二叉树最大距离函数
    function MaxDistance. develop MaxDistance with assistance from other three functions
    GetAncesters: get all ancester nodes of specied nodes.
    GetHighestLevelNodes: get nodes with highest level. 
    GetHighestLevel: get sub-tree's highest level
    main steps:
    1.find nodes with highest level.
    2.select one and find its ancesters.
    3.find the max distance*/
vector<BiTNode*> GetAncesters(BiTNode* root, BiTNode* node);
vector<BiTNode*> GetHighestLevelNodes(BiTNode* root);
int GetHighestLevel(BiTNode* root);
int MaxDistance(BiTNode* root){
    if (root == NULL) return 0;
    vector<BiTNode*> candidates = GetHighestLevelNodes(root);
    BiTNode* candidate = candidates[0];
    vector<BiTNode*> ancesters = GetAncesters(root, candidate);
    int max = 0;
    for(BiTNode* ancester: ancesters){
        max =
            max > (GetHighestLevel(ancester -> lchild) + GetHighestLevel(ancester -> rchild) + 2)?
            max : (GetHighestLevel(ancester -> lchild) + GetHighestLevel(ancester -> rchild) + 2);
    }
    return max;
}
/* add function CreatBinTree for test */
void CreatBinTree(istream &in, BiTNode* &BT);
/* MAIN FUNCTION FOR TEST */
int main(){
    BiTNode* root = new BiTNode(NULL);
    /* test with main function. to test you can input string. 
    example: A(a, b(c, d( e, f)))#
    input without '#' is permitted. insert ' '(space) into string is also permintted.
    */
    CreatBinTree(cin, root);
    cout << endl << "LCA of A,B: " << getLCA(root, 'A', 'B') -> data << endl;;
    cout << MaxDistance(root) << endl;
    system("pause");
    return 0;
}










/* 
below: assistance functions 
*/
bool PreOrderSearchValue(BiTNode* ancester, char value){
    if (!ancester) return false;
    vector<BiTNode*> vec;
    BiTNode *p = ancester;
    while(!vec.empty()||p != NULL){
        while(p != NULL){
            if(value == p -> data) return true;
            vec.push_back(p);
            p = p -> lchild;
        }
        if(!vec.empty()){
            p = vec.back();
            vec.pop_back();
            p = p -> rchild;
        }
    }
    return false;
}
void CreatBinTreeHelper(istream &in, BiTNode* &parent){
    char ch;
    int flag = 0;
    BiTNode *child;
    while(in >> ch){
        switch(ch){
            case ',':
                flag ++;
                break;
            case ')':
                return;
            case ' ':
                break;
            case '(':               
                CreatBinTreeHelper(in, child);
                break;
            default:
                child = new BiTNode(ch);
                if(!flag) parent -> lchild = child;
                else parent -> rchild = child;
        }
    }
}
void CreatBinTree(istream &in, BiTNode* &BT){
    if(!in){BT = NULL; return;}
    char ch; in >> ch; BT -> data = ch; in >> ch;
    CreatBinTreeHelper(in, BT);    
}
vector<BiTNode*> GetAncesters(BiTNode* root, BiTNode* node){
    vector<BiTNode*> ancesters;
    BiTNode* child = node;
    while(child != root){
        vector<BiTNode*> preorder;
        BiTNode* parent = root;
        int flag = 0;
        while(!preorder.empty()||child != NULL){
            while( parent!= NULL){
                if (parent -> lchild == child||parent -> rchild == child){
                    flag++;
                    ancesters.push_back(parent);
                    break;
                }
                preorder.push_back(parent);
                parent = parent -> lchild;
            }
            if(flag) break;
            if(!preorder.empty()){
                parent = preorder.back();
                preorder.pop_back();
                parent = parent -> rchild;
            }
        }
        child = parent;
    }
    return ancesters;
}
vector<BiTNode*> GetHighestLevelNodes(BiTNode* root){  //vector实现队列操作
    vector<BiTNode*> queue; if (root == NULL) return queue; 
    int count = 1;
    queue.push_back(root);
    while(!queue.empty()){
        int temp = 0;
        for(int i = 0; i < count; i++){
            if (queue[i] -> lchild != NULL) queue.push_back(queue[i] -> lchild);
            if (queue[i] -> rchild != NULL) queue.push_back(queue[i] -> rchild);
        }
        temp = queue.size();
        if (temp == count) break;
        queue.erase(queue.begin(), queue.begin() + count);
        count = queue.size();
    }
    return queue;
}
int GetHighestLevel(BiTNode* root){
    int level = 0; if(root == NULL) return level;
    int count = 1;
    vector<BiTNode*> queue;
    queue.push_back(root);
    while(!queue.empty()){
        int temp = 0;
        for(int i = 0; i < count; i++){
            if (queue[i] -> lchild != NULL) queue.push_back(queue[i] -> lchild);
            if (queue[i] -> rchild != NULL) queue.push_back(queue[i] -> rchild);
        }
        temp = queue.size();
        if (temp == count) break;
        queue.erase(queue.begin(), queue.begin() + count);
        count = queue.size();
        level++;
    }
    return level;
}
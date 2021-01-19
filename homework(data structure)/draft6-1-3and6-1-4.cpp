#include<iostream>
#include<vector>
using namespace std;
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
    BiTNode(char value){
        data = value;
        lchild = NULL; rchild = NULL;
    }
};
void PosOrder(BiTNode* root){
    vector<BiTNode*> Stack;
    vector<BiTNode*> OutPut;
    BiTNode* p = root;
    while(p != NULL||!Stack.empty()){
        while(p!=NULL){
            Stack.push_back(p);
            OutPut.push_back(p);
            p = p -> rchild;
        }
        if(!Stack.empty()){
            p = Stack.back();
            Stack.pop_back();
            p = p -> lchild;
        }
    }
    while(!OutPut.empty()){
        p = OutPut.back();
        cout << p -> data << '\t';
        OutPut.pop_back();
    }
}
void PreOrder(BiTNode *root){
    vector<BiTNode*> vec;
    BiTNode *p = root;
    while(!vec.empty()||p != NULL){
        while(p != NULL){
            if(p -> data == NULL) cerr << "data is null" << endl;
            putchar(p -> data); cout << '\t';
            vec.push_back(p);
            p = p -> lchild;
        }
        if(!vec.empty()){
            p = vec.back();
            vec.pop_back();
            p = p -> rchild;
        }
    }
}
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
int main(){
    BiTNode* root = new BiTNode(NULL);
    CreatBinTree(cin, root);
//    cout << endl << "LCA of A,B: " << getLCA(root, 'A', 'B') -> data << endl;;
//    vector<BiTNode*> highestNodes = GetHighestLevelNodes(root);
//    BiTNode* p = highestNodes[0];
//    vector<BiTNode*> ancesters =  GetAncesters(root, p);
//    for(BiTNode* elem: ancesters) cout << elem -> data << endl;
//    cout << GetHighestLevel(root) << endl;
    cout << MaxDistance(root) << endl;
    system("pause");
    return 0;
}
//log1：文件名中含有‘、’导致文件编译出错
//log2: 野指针问题导致函数CreatBinTree的第一句赋值操作出现问题；
//log3: getLCA函数成功输出结果
//log4: 测试了先根遍历与后根遍历，输出结果基本正确
//log5: 测试GetHighestLevelNodes函数，输出正确结果
//log6: 测试GetAncesters函数，输出正确结果
//log6: 测试GetHighestLevel函数，输出正确结果
//log7: 测试MsxDistance函数，输出正确结果
/* 尝试用更加简洁有序的方式写函数，让程序以尽量优美的方式呈现，减少不必要的逻辑与聱牙诘屈的表达 */
#include<iostream>
#include<vector>
using namespace std;
struct BinNode{
    int data;
    BinNode *lchild, *rchild;
    BinNode(int value){
        data = value;
        lchild = NULL; rchild = NULL;
    }
};
void input(vector<int> nums, BinNode *&BT){
    vector<BinNode*> queue; int value, count = 1;
    value = nums.front(); nums.erase(nums.begin());
    BT -> data = value; 
    BinNode* newNode;
    queue.push_back(BT); 
    while(!queue.empty()){
        for(int i = 0; i < count; i++){
            value = nums.front(); nums.erase(nums.begin());
            if(value != -1){
                newNode = new BinNode(value);
                queue[i] -> lchild = newNode;
                queue.push_back(newNode);
            }
            value = nums.front(); nums.erase(nums.begin());
            if(value != -1){
                newNode = new BinNode(value);
                queue[i] -> rchild = newNode;
                queue.push_back(newNode);
            }
        }
        if(nums.empty()) return;
        queue.erase(queue.begin(), queue.begin()+count);
        count = queue.size();
    }
}
vector<BinNode*> GetAncesters(BinNode* root, BinNode* node){
    vector<BinNode*> ancesters; ancesters.push_back(node);
    BinNode* child = node;
    while(child != root){
        vector<BinNode*> preorder;
        BinNode* parent = root;
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
vector<BinNode*> GetHighestLevelNodes(BinNode* root){  //vector实现队列操作
    vector<BinNode*> queue; if (root == NULL) return queue; 
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
bool JudgeNum(vector<int> nums, int value){
    int size = nums.size(), sum = 0, flag = 0;
    /* for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = i; j < size; j++){
            sum += nums[j];
            if(sum == value) return true;
        }
    } */
    /* cout << value << '\t'; */
    for(int i = size -1; i >= 0; i--){
        sum += nums[i];
        /* cout << sum << '\t'; */
        if (sum == value) return true;
    }
    return false;
}
bool SumExist(BinNode* root, int value){
    cout << value << endl;
    vector<BinNode*> highestNodes = GetHighestLevelNodes(root);
    int size = highestNodes.size();
    for(int i = 0; i < size; i++){
        vector<BinNode*> ancesters = GetAncesters(root, highestNodes[i]);
        vector<int> anNum;
        int anSize = ancesters.size();
        for(int j = 0; j <anSize; j ++){
            anNum.push_back(ancesters[j] -> data);
        }
        /* for(int value: anNum) cout << value << '\t';
        cout << endl; */
        if(JudgeNum(anNum, value)) return true;
        /* else cout << endl << "false" << '\t'; */
    }
    return false;
}
int main(){
    vector<int> nums; int value;
    while(cin >> value) {
        nums.push_back(value);
        if(cin.get() == '\n') break;
    }
    BinNode* root = new BinNode(NULL);
    input(nums, root);
    cin >> value; 
    cout << value << endl;
    /* vector<BinNode*> highestNodes = GetHighestLevelNodes(root);
    for(BinNode* elem: highestNodes) 
        cout << elem -> data << '\t';
    cout << endl;
    for(BinNode* elem: highestNodes){
        vector<BinNode*> ancesters = GetAncesters(root, elem);
        for(BinNode* elem: ancesters) 
            cout << elem -> data << '\t';
        cout << endl;
    } */
    cout << boolalpha << SumExist(root, value);
    system("pause");
    return 0;
}
//log1: output false ,while expect true.
//log2: highestNodes, GetAncesters output right results.
//log3: add debugging stuff into program, ouput three false as expected.
//log4: change JudgeNum function, still output false, expected true.
//log5: change SumExist function, anNum output as expected, while Judge output false, expected true.
//log6: change JudgeNum function, value show as 0, expected 30;
//log7: 3 was output, regared as input, no bug exsists.
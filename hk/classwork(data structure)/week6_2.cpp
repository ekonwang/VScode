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
void io(vector<int> nums, BinNode *&BT){
    vector<BinNode*> queue; int value, count = 1;
    value = nums.front(); nums.erase(nums.begin());
    BT -> data = value; cout << value;
    BinNode* newNode;
    queue.push_back(BT); 
    while(!queue.empty()){
        float sum = 0, a = 0;
        for(int i = 0; i < count; i++){
            value = nums.front(); nums.erase(nums.begin());
            if(value != -1){
                newNode = new BinNode(value);
                queue[i] -> lchild = newNode;
                queue.push_back(newNode);
                a ++; sum += value;
            }
            value = nums.front(); nums.erase(nums.begin());
            if(value != -1){
                newNode = new BinNode(value);
                queue[i] -> rchild = newNode;
                queue.push_back(newNode);
                a ++; sum += value;
            }
        }
        cout << ' ' << sum/a;
        if(nums.empty()) return;
        queue.erase(queue.begin(), queue.begin()+count);
        count = queue.size();
    }
}

int main(){
    vector<int> nums; int value;
    while(cin >> value) {
        nums.push_back(value);
        if(cin.get() == '\n') break;
    }
    BinNode* root = new BinNode(NULL);
    io(nums, root);
    //system("pause");
    return 0;
}
//log1: if(!in)位置太靠前，导致最后一次没能输出
//log2: 调换之后依然没能够输出
//log3: 发现queue没有入列操作
//log4: “网络oj提示答案过长” 
//log5: 加入cin.get()依然有问题，if(!nums.empty())使用错误
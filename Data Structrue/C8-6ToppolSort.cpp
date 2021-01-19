#include "Graph.h"
#include <stack>
using namespace std;
template <class NameType>
void Graph<NameType>::ToppolSort(){
    int top = -1;
    for(int i = 0; i < n; i++){
        count[i] = top;
        top = i;
    }
    for(i = 0; i< n; ++i){
        if(top == -1){
            cout << "Network has a Circle!" << endl;
            return;
        }
        else{
            int j = top;
            top = count[top];
            cout << j << endl;
            EdgeNode * l = NodeTable[j] -> adj;
            top = -1;                                 //原程序没有这一步
            while(1){
                if(l == NULL) break;
                int k = l -> dest;
                if(--count[k] == 0){
                    count[k] = top;
                    top = k;
                }
                l = l -> link;
            }
        }
    }

}
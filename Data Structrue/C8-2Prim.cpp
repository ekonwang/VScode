#include <iostream>
#include "Graph.h"
using namespace std;
const int MAXINT = 9999;
template <class NameType>
void Graph<NameType>::Prim(int n, int u) {
    int Min;
    int VerticesNum = VerticesCurrentNum;
    double * LowCost = new double[VerticesNum + 1];
    int * CloseSet = new int [VerticesNum + 1];
    int i, j, k;
    for(i = 1; i <= VerticesNum; ++i){
        LowCost[i] = A[u][i];
        CloseSet[i] = u;
    }
    for(i = 1; i < VerticesNum; ++i){
        Min = MAXINT;
        for(j = 1; j <= VerticesNum; ++j)
            if(LowCost[j] != 0 && LowCost[j] < Min){
                Min = LowCost[j];
                k = j;                      // Find Current Minimum Edge.
            }
        cout << CloseSet[k] << k << Min;
        LowCost[k] = 0;
        for(j = 1; j <= VerticesNum; ++j)
            if(Cost[k][j] != 0 && Cost[k][j] < LowCost[j])
            {
                LowCost[j] = Cost[k][j];
                CloseSet[j] = k;
            }
    }
}

// 宏定义后面不需要加上';'
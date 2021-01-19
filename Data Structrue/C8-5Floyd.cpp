/* O(n3) */
#include "Graph.h"
using namespace std;
#define MAXINT 100
template <class NameType>
void Graph<NameType>::Floyd(int n){
    int i, j, k;
    for(int i = 1; i <= n; ++j){
        Adj[i][j] = A[i][j];
        if( i != j && Adj[i][j] < MAXINT )
            Path[i][j] = i;
        else Path[i][j = 0;
    }
    /* can not understand */
    for(k = 1; k <= n, ++k)
        for(i = 1; i<= n; ++i)
            for(j = 1; j <= n; ++j)
                if(Adj[i][k] + Adj[k][j] < Adj[i][j])
                {
                    Adj[i][j]  =Adj[i][k] + Adj[k][j];
                    Path[i][j] = k;
                }
}
#include <iostream>
#include "Graph.h"
#define MAXINT 5000
#define MAXV 100
using namespace std;
int a[MAXV] = {0};         //并查集数组
int fd(int x);
void cb(int x, int y);
template <class NameType>
void Graph<NameType>::Kruscal(int n, int v){
    int v[MAXV][MAXV] = {0};     //边排序数组
    int VerticesNum = VerticesCurrentNum, n = VerticesNum * (VerticesNum - 1) / 2, i, j, k;
    double Edges[MAXINT][3] = {0}, t;
    for(int i = 1; i <= VerticesNum; ++i) a[i] = i;

    for(k = 0; k < n; ++k){             //preparing
        t = MAXINT;
        for(i = 1; i < VerticesNum; ++i)
            for(j = i + 1; j <= VerticesNum; ++j){
                if(A[i][j] && A[i][j] < t && !v[i][j]) t = A[i][j];
            }
        if(t == MAXINT) break;
        for(i = 1; i < VerticesNum; ++i)
            for(j = i + 1; j <= VerticesNum; ++j){
                if(A[i][j] == t) {Edges[k][0] = t; Edges[k][1] = i; Edges[k][2] = j; }
            }
        v[ Edges[k][1] ][ Edges[k][2] ] = 1;
    }

    for(int i = 0; i < k; i++){
        if( fd( Edges[i][1] ) != fd( Edges[i][2]) ) {
            cb(Edges[i][1], Edges[i][2]);
            cout << Edges[i][1] << '\t' < Edges[i][2] << '\t' << Edges[i][0] << endl;
        }
    }
}

int fd(int x){             //直接用并查集即可
    if(x == a[x]) return x;
    else return (a[x] = fd(a[x])); 
}
void cb(int x, int y){
    a[fd(x)] = fd(y);
}
#include <iostream>
#define VerticesNum 99
#define MAXINT 9999
using namespace std;
float Cost[VerticesNum][VerticesNum];
float Dist[VerticesNum];
int Pre[VerticesNum];
int S[VerticesNum];
void ShortestPath(int n, int v){
    int i, j , k;
    float Min;
    for(i = 1; i <= n; ++i){
        Dist[i] = Cost[v][i];
        S[i] = 0;
        if(Dist[i] < MAXINT)
            Pre[i] = v;
        else Pre[i] = 0;
    }
    S[v] = 1;
    Pre[v] = 0;
    for(i = 1; i <= n; i++){
        Min = MAXINT;
        k = 0;
        for(j = 1; j <= n; j++)
            if(S[j] == 0)
                if(Dist[j] != 0 && Dist[j] < Min){
                    Min = Dist[j];
                    k = j;
                }
            if (k == 0) continue;
            S[k] = 1;
            for(j = 1; j <= n; ++j)
                if(S[j] == 0 && Cost[k][j] < MAXINT)
                    if(Dist[k] + Cost[k][j] < Dist[j]){
                        Dist[j] = Dist[k] + Cost[k][j];
                        Pre[j] = k;
                    }
    }
}
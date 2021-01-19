#include <iostream>
#include <queue>
using namespace std;
int VerticesNumber = 10;
void DFS_helper(int v, int Visited[]);
int GetFirstNeighbor(int v);
int GetNextNeighbor(int v, int w);
template <class NameType, class DistType> 
void DFS(){
    int * Visited[] = new int[VerticesNumber];
    for(int i = 0; i < VerticesNumber; i++)
        Visited[i] = 0;
    DFS_helper(0, Visited);
    delete [] Visited;
}
template <class NameType, class DistType>
void DFS_helper(int v, int Visited[]){
    cout << v;
    Visited[v] = 1;
    int w = GetFirstNeighbor(v);
    while(w != -1){
        if( !Visited[w] )
            DFS_helper(w, Visited);
        w = GetNextNeighbor(v, w);
    }
}
template <class NameType, class DistType>
void BFS(int v){
    int * Visited = new int [VerticesNumber];
    for(int i = 0; i < VerticesNumber; ++i)
        Visited[i] = 0;
    cout << v;
    Visited[v] = 1;
    queue <int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front(); q.pop();
        int w = GetFirstNeighbor(v);
        while( w != -1){
            if(!Visited[w]){
                cout << w << ' ';
                Visited[w] = 1;
                q.push(w);
            }
            w = GetNextNeighbor(v, w);
        }
    }
    delete [] Visited;
}
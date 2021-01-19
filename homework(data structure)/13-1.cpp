#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

template<class NameType> struct node{
    NameType data;
    node<NameType>* lchild, *rchild;
    node(NameType val){data = val; lchild = rchild = NULL; }
};

const int EdgesMaxNum=100;  // max edges num
const int VerticesMaxNum=20;  // max vertices num
template <class NameType, class DistType> class Graph { 
    private:
        NameType vertices[VerticesMaxNum];
        DistType A[VerticesMaxNum][VerticesMaxNum]; 
        int EdgesCurrentNum;
        int VerticesCurrentNum;
    public:
        Graph(NameType val[], int size=VerticesMaxNum)//construction function
        {   
            if (size > VerticesMaxNum) 
                cerr << "Error: construction function. size too large." << endl;
            for(int i=0; i<size; i++)
            for(int j=0; j<size; j++) A[i][j]=0;
            for(int i = 0; i < size; i++) vertices[i] = val[i];
            EdgesCurrentNum=0;
            VerticesCurrentNum = size;
        }
        int GraphEmpty() const;   
        int GraphFull() const;
        int VerticesNumber( ) { return VerticesCurrentNum;}
        int EdgesNumber( ) { return EdgesCurrentNum; }
        DistType GetWeight(int v1, int v2);
        int GetFirstNeighborVer(int v);
        int GetNextNeighborVer(int v1, int v2);
        void InsertVertex(const NameType &vertex);
        void InsertEdge(int v1, int v2, DistType weight = 1)//insert an edge with weight
        {
            if(weight == 0)
                cerr << "Error: insertEdge. insertion failed." << endl;
            A[v1][v2] = A[v2][v1] = weight;
            cout << "Value: " << weight << " insertion completed." << endl;
        }
        void InsertEdge(DistType **matrix, int size)//insert an edge with weight
        {
            if(size > VerticesCurrentNum) 
                cerr << "Error: insertEdges. insertion failed." << endl;
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j ++){
                    A[i][j] = matrix[i][j];
                }
            }
        }
        void RemoveEdge(int v1, int v2);
        void showEdges(){
            cout << endl << "edges: " << endl;
            for(int i = 0; i < VerticesCurrentNum; i++){
                for(int j = 0; j < VerticesCurrentNum; j++){
                    cout << A[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        void DFS(node<NameType> *& root, int cur, int init = 1);
};

//如果有默认形参，只需在声明中指定一次

int visited[VerticesMaxNum];
template<class NameType, class DistType>
void Graph<NameType, DistType> :: DFS(node<NameType> *& root, int cur, int init){
    if(init == 1) memset(visited, 0, sizeof(visited));
    int flag = 0, pos = 0;
    visited[cur] = 1;
    root = new node<NameType>(vertices[cur]);
    for(; pos < VerticesCurrentNum; pos++){
        if (!visited[pos] && A[cur][pos]) {
            if(flag == 0){
                DFS(root -> lchild, pos, 0);
                flag ++;
            }else if(flag == 1){
                DFS(root -> rchild, pos, 0);
                flag ++;
                break;
            }
        }
    }
}

template<class NameType>
void Travesal(node<NameType> *&root){
    queue<node<NameType>*> Q;
    node<NameType>* p = root;
    Q.push(p);
    while(!Q.empty()){
        int len = Q.size();
        for(int i = 0; i < len; i++){
            p = Q.front();
            Q.pop();
            if(p == NULL) cout << -1 << ' ';
            else{
                Q.push(p -> lchild); Q.push(p -> rchild);
                cout << p -> data << ' ';
            } 
        }
        cout << endl;
    }
}

int main(){
    node<char>* root;
    char data[5] = {'a', 'b', 'c', 'd', 'e'};
    int **mtx = new int* [5];
    int mtxA[5] = { 0, 1, 0, 0, 1};
    int mtxB[5] = { 1, 0, 1, 0, 0};
    int mtxC[5] = { 0, 0, 0, 1, 0};
    int mtxD[5] = { 0, 0, 0, 0, 0};
    int mtxE[5] = { 0, 0, 0, 0, 0};
    mtx[0] = mtxA;
    mtx[1] = mtxB;
    mtx[2] = mtxC;
    mtx[3] = mtxD;
    mtx[4] = mtxE;

    Graph<char, int> g(data, 5);
    g.InsertEdge(mtx, 5);
    g.DFS(root, 0);
    Travesal(root);
    system("pause");
    return 0;
}







#include<iostream>
using namespace std;
#define VerticesMaxNum 20

/* declaration and definition of classes. */
template<class NameType, class DistType> class Graph;
template<class NameType, class DistType> class EdgeNode {
    friend class Graph<NameType, DistType>;
        int dest;
        DistType cost;
        EdgeNode<NameType, DistType> * link;
    public:
        EdgeNode(int d, DistType c): dest(d), cost(c), link(NULL){} // construction.
};

template<class NameType, class DistType> class VertexNode{
    friend class EdgeNode<NameType, DistType>;
    friend class Graph<NameType, DistType>;
        NameType data;
        EdgeNode <NameType, DistType>* adj;
        VertexNode(NameType val): data(val), adj(NULL) {}
        VertexNode(){adj = NULL;}
};

template<class NameType, class DistType> class Graph{
        VertexNode <NameType, DistType> NodeTable[VerticesMaxNum];
        int VerticesNum;
        int EdgesNum;
        int GetVertexPos(const NameType &vertex);
    public:
        Graph(int size);  //construction.
        Graph(int v, NameType vs[], DistType ** mtx); //cosntruction vB.
        ~Graph(){}       //destruction.
        int VerticesNumber(){return VerticesNum;}
        int EdgesNumber(){return EdgesNum;}    
        void insert(int i, int j);
        void delArc(int i, int j);
        void delEdge(int i, int j);  
        void showGraph();
};


/* delArc函数  两次有向边的删除等价于无向图中边的删除*/
template<class NameType, class DistType> 
void Graph<NameType, DistType> :: delArc(int i, int j){
    this -> delEdge(i, j);
    this -> delEdge(j, i);
}

/* test code */
int main(){
    char ch[5] = {'a', 'b', 'c', 'd', 'e'};
    int **mtx = new int* [5];
    int mtxA[5] = { 0, 1, 0, 0, 1};
    int mtxB[5] = { 1, 0, 1, 0, 0};
    int mtxC[5] = { 0, 1, 0, 1, 0};
    int mtxD[5] = { 0, 0, 1, 0, 0};
    int mtxE[5] = { 1, 0, 0, 0, 0};
    mtx[0] = mtxA;
    mtx[1] = mtxB;
    mtx[2] = mtxC;
    mtx[3] = mtxD;
    mtx[4] = mtxE;

    Graph<char, int> g(5, ch, mtx);
    g.showGraph();
    g.delArc(0, 1);
    g.showGraph();
    system("pause");
    return 0;
}


/* assitance functions: construction func etc. */
template<class NameType, class DistType> 
Graph<NameType, DistType> :: Graph(int v, NameType vs[], DistType **mtx){

    VerticesNum = v;
    for(int i = 0; i < v; i++){
        NodeTable[i].data = vs[i];
    }
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(mtx[i][j]){
                this -> insert(i, j);
            }
        }
    }
}


template<class NameType, class DistType> 
void Graph<NameType, DistType> :: showGraph(){
    EdgeNode<NameType, DistType> * p;
    for(int i = 0; i < VerticesNum; i++){
        p = NodeTable[i].adj;
        while(p != NULL) {cout << p -> dest << ' '; p = p -> link;}
        cout << endl;
    }
    cout << endl;
}

template<class NameType, class DistType> 
void Graph<NameType, DistType> :: insert(int i, int j){
    EdgeNode<NameType, DistType> *p = NodeTable[i].adj, *q = new EdgeNode<NameType, DistType>(j ,1);
    if(p == NULL) NodeTable[i].adj = q;
    else{
        if(p -> dest > j) {
            q -> link = p;
            NodeTable[i].adj = q;
        }else{
            while(p -> link != NULL && p -> link -> dest < j) p = p -> link;
            if(p -> link == NULL) p -> link = q;
            else{
                q -> link = p -> link;
                p -> link = q;
            }
        }
    }
}

template<class NameType, class DistType> 
void Graph<NameType, DistType> :: delEdge(int i, int j){
    EdgeNode<NameType, DistType> *p = NodeTable[i].adj, *q = p;
    if(p -> dest == j){
        NodeTable[i].adj = p -> link;
    }else{
        while(q -> link != NULL && q -> link -> dest != j) q -> link;
        if(q -> link == NULL) 
            cerr << "Error: delEdge. NO such edge exists." << endl;
        else{
            p = q -> link;
            q -> link = p -> link;
        }
    }
    delete p; 
}
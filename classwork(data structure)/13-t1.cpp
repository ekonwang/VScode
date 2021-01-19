#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define N 30
#define VerticesMaxNum 30
int a[N][N] = {0};
int visited[N] = {0};

int input(){
    int val, n = 0;
    char ch;
    while(cin >> val){
        a[0][n++] = val;
        if(cin.get() != ',') break;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j ++){
            cin >> val;
            if(j != n - 1) cin >> ch;
            a[i][j] = val;
        }
    }

    return n;
}

/* declaration and definition of classes. */
template<class NameType, class DistType> class Graph;
template<class NameType, class DistType> class EdgeNode {
    friend class Graph<NameType, DistType>;
        int dest;
        int cost;
        EdgeNode<NameType, DistType> * link;
    public:
        EdgeNode(int d, DistType c): dest(d), cost(c), link(NULL){} // construction.
};
template<class NameType, class DistType> class VertexNode{
    friend class EdgeNode<NameType, DistType>;
    friend class Graph<NameType, DistType>;
        char data;
        EdgeNode <NameType, DistType>* adj;
        VertexNode(char val): data(val), adj(NULL) {}
        VertexNode(){adj = NULL;}
};
template<class NameType, class DistType> class Graph{
        VertexNode <NameType, DistType> NodeTable[VerticesMaxNum];
        int VerticesNum;
        int EdgesNum;
        int GetVertexPos(const NameType &vertex);
    public:
        Graph(int size);  //construction.
        Graph(int v, char vs[], int mtx[][N]); //cosntruction vB.
        ~Graph(){}       //destruction.
        int VerticesNumber(){return VerticesNum;}
        int EdgesNumber(){return EdgesNum;}    
        void insert(int i, int j);
        void insert_weight(int i, int j, int w);
        void delArc(int i, int j);
        void delEdge(int i, int j); 
        void showGraph();
        vector<string> prim(int init, int arg = 1);
        int FdVmin(int i);
};

template<class NameType, class DistType> 
void Graph<NameType, DistType> :: insert_weight(int i, int j, int w){
    EdgeNode<NameType, DistType> *p = NodeTable[i].adj, *q = new EdgeNode<NameType, DistType>(j ,w);
    if(p == NULL) NodeTable[i].adj = q;
    else{
        if(p -> cost > w) {
            q -> link = p;
            NodeTable[i].adj = q;
        }else{
            while(p -> link != NULL && p -> link -> cost < w) p = p -> link;
            if(p -> link == NULL) p -> link = q;
            else{
                q -> link = p -> link;
                p -> link = q;
            }
        }
    }
}

template<class NameType, class DistType> 
Graph<NameType, DistType> :: Graph(int v, char vs[], int mtx[][N]){
    VerticesNum = v;

    for(int i = 0; i < v; i++){
        NodeTable[i].data = vs[i];
    }
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(mtx[i][j]){
                this -> insert_weight(i, j, mtx[i][j]);
            }
        }
    }
}

template<class NameType, class DistType> 
void Graph<NameType, DistType> :: showGraph(){
    EdgeNode<NameType, DistType> * p;
    for(int i = 0; i < VerticesNum; i++){
        p = NodeTable[i].adj;
        cout << NodeTable[i].data << ": ";
        while(p != NULL) {cout << NodeTable[p -> dest].data << ' '; p = p -> link;}
        cout << endl;
    }
    cout << endl;
}

template<class NameType, class DistType> 
vector<string> Graph<NameType, DistType> :: prim(int init, int arg){
    vector<string> vec;
    visited[init] = 1;
    int min = 999, t;
    EdgeNode<NameType, DistType> *p;
    for(int i = 0; i < VerticesNum; i++){
        if(visited[i]){
            t = FdVmin(i);
            min = t < min ? t : min;
        }
    }
    for(int i = 0; i < VerticesNum; i++){
        if(visited[i]){
            p = NodeTable[i].adj;
            while(p != NULL){
                if(p -> cost == min && !visited[p -> dest]){
                    vector<string>subvec = prim(p -> dest, 0);
                    string s(1, NodeTable[i].data);
                    s += NodeTable[p -> dest].data;
                    if(subvec.size() == 0){
                        vec.push_back(s);
                    }else{
                        for(string str: subvec) vec.push_back(s + str);  
                    }
                }
                p = p -> link;
            }
        }
    }
    visited[init] = 0;

    if(arg == 1){
        char ch[2];
        int val[2];
        EdgeNode<NameType, DistType> *p;
        for(string str: vec){
            for(int i = 0; i < VerticesNum - 1; i++){
                for(int j = 0; j <= 1; j++){
                    ch[j] = str[2 * i + j];
                    val[j] = ch[j] - 'A';
                }
                p = NodeTable[val[0]].adj;
                while(p -> dest != val[1]) p = p -> link;
                cout << '(' << ch[0] << ", " << ch[1] << ", " << p -> cost << ')';
                if(i != VerticesNum - 2) cout << ", "; 
            }
            cout << endl;
        }
    }

    return vec;
}

template<class NameType, class DistType> 
int Graph<NameType, DistType> :: FdVmin(int i){
    int min = 999;
    EdgeNode<NameType, DistType> * p = NodeTable[i].adj;
    if(p != NULL){
        while(p != NULL) {
            if(!visited[p -> dest])
                min = min < p -> cost ? min : p -> cost;
            p = p -> link;
        }
    }
    return min;
}

int main(){
    int v;
    char c;
    v = input();
    cin >> c;
    char ch[26];
    for(int i = 0; i < 26; i++) ch[i] = (char) ('A' + i);
    Graph<char, int> g(v, ch, a);
    g.showGraph();
    g.prim(c - 'A');
    system("pause");
    return 0;
}




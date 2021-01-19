#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include "SeqList.h"
using namespace std;
/* 关键词 friend 常写错导致各种问题 */
const int EdgesMaxNum=100;  //最大边数
const int VerticesMaxNum=20;  //最大顶点数

class EdgeNode;
template<class NameType> class VertexNode;

template <class NameType> class Graph { 
    friend EdgeNode;
    friend VertexNode<NameType>;
    private:
        SeqList <NameType> VerticesList[VerticesMaxNum + 1];
        VertexNode <NameType> * NodeTable[VerticesMaxNum + 1];
        double A[VerticesMaxNum + 1][VerticesMaxNum + 1];  //邻接矩阵
        double Adj[VerticesMaxNum + 1][VerticesMaxNum + 1];
        int Path[VerticesMaxNum + 1][VerticesMaxNum + 1];
        int EdgesCurrentNum;  //当前边数
        int VerticesCurrentNum;  //当前顶点数
        int *Count;              //用于记录入度个数 拓扑排序用到
    public:
        Graph(int size=VerticesMaxNum);  //构造函数
        Graph(float ** matrix);
        int GraphEmpty( ) const { return VerticesList.IsEmpty( ); }         
        //判断图为空否
        int GraphFull( ) const  //判断图为满否
        { return VerticeList.IsFull( ) || EdgesCurrentNum == EdgesMaxNum; }
        int VerticesNumber( ) { return VerticesCurrentNum; }
        //返回当前顶点数t.end
        int EdgesNumber( ) { return EdgesCurrentNum; }
        //返回当前边数
        double GetWeight(int v1, int v2);
        //给出以顶点v1和v2为两端点的边上的权值
        int GetFirstNeighborVer(int v);
        //给出顶点v的第一个邻接顶点的位置
        int GetNextNeighborVer(int v1, int v2);
        //给出顶点v1的某邻接顶点v2的下一个邻接顶点
        void InsertVertex(const NameType &vertex);
        //插入新顶点vertex
        void InsertEdge(int v1, int v2, double weight);
        //插入权值为weight一条新边(v1, v2)
        void RemoveVertex(int vertex);
        //删除顶点vertex和所有与它相关联的边
        void RemoveEdge(int v1, int v2);
        //在图中删去边(v1, v2)



        void Prim(int n, int u); // Prim Algorithm.
        void Kruscal(int n, int u); // Kruscal Algorithm.
        void Floyd(int n);       // Floyd Algorithm
        void ToppolSort();       // ToppolSort
};



template <class NameType> 
Graph <NameType> :: Graph(int size = VerticesMaxNum)
{  //构造函数
    for (int i=0; i<=size; i++)  //邻接矩阵初始化
    for (int j=0; j<=size; j++)
        A[i][j]=0;
    EdgesCurrentNum = 0;  //图中当前边数初始化
    VerticesCurrentNum = 0;
}

template <class NameType>
double Graph <NameType> ::GetWeight(int v1, int v2)
{  //给出以顶点v1和v2为两端点的边上的权值
        if (v1!=-1 && v2!=-1)
	 return A[v1][v2];
        else return 0;  //带权图中权值为0，表示无权值
}

template<class NameType> class VertexNode{
    NameType data;
    EdgeNode * adj;
};
class EdgeNode{
    double cost;
    EdgeNode * link;
    int dest;
};

#endif // _GRAPH_H_
#include <iostream>
using namespace std;
#define MAXN 100
struct HuffmanNode
{
    char data;
    int lchild;
    int rchild;
};
HuffmanNode * creat_huffman_tree(char a[], int w[], int n){
    HuffmanNode * nodes = new HuffmanNode[2 * MAXN - 1];
    int n1, n2;
    int min1, min2;
    int i, j;
    int u, v;
    if(n > MAXN){
        cout << "节点数过多" << endl;
        return NULL;
    }
    for(int i = 0; i < n; i++){
        nodes[i].data = a[i];
        nodes[i].lchild = -1;
        nodes[i].rchild = -1;
        w[i] = -w[i];
    }
    for(i = n; i < 2*n - 1; i++){
        n1 = -1;
        min1 = 9999;
        n2 = -1;
        min2 = 9999;
        for(j = 0; j < i; j++){
            v = w[j];
            u = -v;
            if(u > 0)
                if(u < min1){
                    min2 = min1;
                    n2 = n1;
                    min1 = u;
                    n1 = j;
                }
                else if(u < min2){
                    min2 = u;
                    n2 = j;
                }
        }
        nodes[i].data = '*';
        nodes[i].lchild = n1;
        nodes[i].rchild = n2;
        w[i] = w[n1] + w[n2];
        w[n1] = -w[n1];
        w[n2] = -w[n2];
    }
    w[2*n - 2] = -w[2*n - 2];
    return &(nodes[2*n - 2]);
}

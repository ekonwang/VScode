#include<iostream>
#include<algorithm>
#define MaxChildren 10
#define BufSize 1001
using namespace std;
struct bitnode{
    int data;
    int child[MaxChildren] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, parent = -1, children = 0;
};
bitnode a[BufSize];
int Max = 0;

int creat_the_tree(){
    int n, m, i = 0, t = 0, x, y;
    bitnode p, q;

    cin >> m >> n;
    for(i = 0; i < n; i++){
        cin >> x >> y;
        a[x].child[a[x].children++] = y;
        a[y].parent = x;
        Max = Max > x ? Max : x;
        Max = Max > y ? Max : y;
    }
    return x;
}
int find_the_root(int x){
    bitnode p = a[x];

    while(p.parent != -1) p = a[p.parent];
    return p.data;
}
int find_the_most(){
    int i = 0, max = 0;
    bitnode p;

    for(i = 0; i < Max; i++){
        max = a[i].children > max ? a[i].children : max;
    }

    for(i = Max - 1; i >= 0; i--){
        if(a[i].children == max) break; 
    }
    p = a[i];

    return p.data;
}
void list_children(int pos){
    bitnode p = a[pos];
    int i = 0, b[MaxChildren] = {0};

    for(i = 0; i < p.children; i++) {
        b[i] = p.child[i];
    }
    sort(b, b+p.children);

    for(i = 0; i < p.children; i++){
        cout << b[i] << ' ';
    }
}
int main(){
    int i = 0, tx = 0;

    for(i = 0; i < BufSize; i++) {
        a[i].data = i;
    }
    tx = creat_the_tree();
    cout << find_the_root(tx) << endl;
    tx = find_the_most();
    cout << tx << endl;
    list_children(tx);

    //system("pause");
    return 0;
}



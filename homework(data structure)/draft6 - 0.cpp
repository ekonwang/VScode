#include<iostream>
#include<vector>
using namespace std;
template <class Type> class GenList;
template <class Type> class GenListNode {
    friend class GenList<Type>;
    friend void CreateListHelper(istream &in, GenListNode<char> *&ls);
private:
    int utype;       //=0/1/2
    GenListNode <Type> *tlink;     //指向同一层下一结点的指针
    union {      //联合
        int ref; Type value;   //utype=0，存放引用计数，=1，存放数值
        GenListNode <Type> *hlink;     //utype=2，存放指向子表的指针
    } info;
public:
    GenListNode<Type>(){utype = -1; tlink = NULL;}
    GenListNode<Type>(int ut){utype = ut; tlink = NULL;}
};
template <class Type> class GenList {  //广义表类定义     
private:
    GenListNode <Type> *first;  //广义表头指针
    GenListNode <Type> * Copy(GenListNode <Type> *ls);
    //复制一个ls指示的无共享非递归表
    int Depth(GenListNode <Type> *ls);			 
    //计算由ls指示的非递归表的深度
    int Length(GenListNode <Type> *ls);			 
    //计算由ls指示的非递归表的长度
public:
    GenList(GenListNode<Type>* p){first = p;}
    //比较以s和t为表头的两个表是否相等
    bool Equal(GenListNode <Type> *ss, GenListNode <Type> *tt);
    //从输入流对象输入广义表的字符串描述
    //建立一个带附加头结点的广义表结构
    void CreateList(istream &in, GenListNode <char> *&ls);
    //输出广义表
    void OutPut(GenListNode<Type> *&ls);
};
template<class Type> void GenList<Type>::CreateList(istream &in, GenListNode <char> *&ls){
    char ch; in >> ch;
    GenListNode<char>* p = new GenListNode<char>();
    CreateListHelper(in, p);
    ls -> tlink = p;
    ls -> info.ref = 0;
}

template<class Type> bool GenList<Type>::Equal(GenListNode<Type> *ss, GenListNode<Type> *tt){
    GenListNode<Type>* s = ss, *t = tt;
    while(s != NULL && s!= NULL){
        if(s -> utype == 0||s -> utype == 1){
            if(s -> utype != t -> utype) return false;
            if(s -> utype == 0) {
                if(s -> info.ref != t -> info.ref) return false;
            }
            else{
                if(s -> info.value != t -> info.value) return false;
            }
        }
        else{
            if (s -> utype != t -> utype) return false;
            if (!Equal(s -> info.hlink, t -> info.hlink)) return false;
        }
        s = s -> tlink; t = t -> tlink;
    }
    if (s != NULL || t != NULL) return false;
    return true;
}
/* main function for test */
int main(){
    /* input ls in line 0 
    input _ls2 in line 1
    output false or true in line 2
    input example: (A, B, C, (D, E), F) */
    GenListNode<char>* ls = new GenListNode<char>(0);
    GenListNode<char>* _ls2 = new GenListNode<char>(0);
    GenList<char> genLst(ls);
    GenList<char> _genLst2(_ls2);
    genLst.CreateList(cin, ls);
    genLst.CreateList(cin, _ls2);
    cout << boolalpha << genLst.Equal(ls, _ls2) << endl;
    system("pause");
    return 0;
}












// assistance function
/* output function: output all nodes' value of ls(ls's included) */
template<class Type> void GenList<Type>::OutPut(GenListNode<Type>* &ls){
    cout << '(';
    GenListNode<Type>* p = ls;
    while(p != NULL){
        if(p -> utype == 1){
            if( p -> tlink != NULL) cout << p -> info.value << ", ";
            else cout << p -> info.value;
        }
        if(p -> utype == 2){
            OutPut(p -> info.hlink);
        }
        p = p -> tlink;
    }
    cout << ')';
}
void CreateListHelper(istream &in, GenListNode<char> *&ls){
    char ch;
    GenListNode<char>* current = ls;
    while(in >> ch){
        switch(ch){
            case ' ':
                break;
            case '(':
                {
                current -> utype = 2;
                GenListNode<char>* subList = new GenListNode<char>();
                current -> info.hlink = subList;
                CreateListHelper(in, subList);
                break;
                }
            case ',':
                {
                GenListNode<char>* newNode = new GenListNode<char>();
                current -> tlink = newNode;
                current = newNode;
                break;
                }
            case ')':
                return;
            default:
                current -> utype = 1;
                current -> info.value = ch;
        }
    }
    cout << endl;
}
//log1: 被重复声明
//log2: line41 p defined as objct, expeced ptr. 
//log3: in << ch, expected in >> ch.
//log4: construction function: expectd ';'before ')'.
//log5: 删除switch中的‘ ’依然输出.
//log6: defined variables in switch are too long to be true, CreatHelper functions; Output not funcion well. 
//log7: add "ls -> tlink = p", output '(' only, expected "(A, B, (C), D) ".
//log8: add "p = p -> tlink;" into OutPut function. out sublist without brace.
//log9: List constrction has recursive step, while output ignore sublist output.
//log10: add debug stuff,List construction has bug, current was transmitted to sublist as begin node.
//log11: output as expected.
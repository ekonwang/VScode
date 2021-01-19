#include<iostream>
#include<vector>
using namespace std;
/* 节点及广义表定义： */
template <class Type> class GenList;
template <class Type> class GenListNode {
    friend class GenList<Type>;
    friend void CreateListHelper(istream &in, GenListNode<char> *&ls);
private:
    int utype;    
    GenListNode <Type> *tlink;    
    union {     
        int ref; Type value;  
        GenListNode <Type> *hlink;    
    } info;
public:
    GenListNode<Type>(){utype = -1; tlink = NULL;}
    GenListNode<Type>(int ut){utype = ut; tlink = NULL;}
};
template <class Type> class GenList {   
private:
    GenListNode <Type> *first; 
    GenListNode <Type> * Copy(GenListNode <Type> *ls);
    int Depth(GenListNode <Type> *ls);			 
    int Length(GenListNode <Type> *ls);			 
public:
    GenList(GenListNode<Type>* p){first = p;}
    bool Equal(GenListNode <Type> *ss, GenListNode <Type> *tt);
    void CreateList(istream &in, GenListNode <char> *&ls);
    void OutPut(GenListNode<Type> *&ls);
};
/* 判断广义表是否相同函数 
   function Equal.
 */
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
    /* you can output genlist in format you have input it.
    genLst.OutPut(ls); genLst.OutPut(_ls2); 
    */
    genLst.CreateList(cin, ls);
    genLst.CreateList(cin, _ls2);
    cout << boolalpha << genLst.Equal(ls, _ls2) << endl;
    system("pause");
    return 0;
}












/* below: 
assistance functions */

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
template<class Type> void GenList<Type>::CreateList(istream &in, GenListNode <char> *&ls){
    char ch; in >> ch;
    GenListNode<char>* p = new GenListNode<char>();
    CreateListHelper(in, p);
    ls -> tlink = p;
    ls -> info.ref = 0;
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
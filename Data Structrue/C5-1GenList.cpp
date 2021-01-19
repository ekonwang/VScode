#include <iostream>
#include <string>
#define HEAD 0
#define INTEGER 1
#define CHAR 2
#define LIST 3
using namespace std;
class GenList;
class GenListNode{
    friend GenList;
    int tag;
    GenListNode * link;
    union {
        int ref;
        int integer_data;
        char char_data;
        GenListNode *dlink;
    } data;
public:
    GenListNode Data(GenListNode * elem);
};
class GenList{
    GenListNode * first;
public:
    GenList(){first = NULL; };
    ~GenList(){};
    GenListNode * Copy(GenListNode * ls);
    int Equal(GenListNode * s, GenListNode * t);
};
GenListNode * GenList::Copy(GenListNode * ls){
    GenListNode * q = NULL;
    if(!ls){
        q = new GenListNode;
        q -> tag = ls -> tag;
        switch(ls -> tag)
        {
            case HEAD : 
                q -> data.ref = ls -> data.ref;
                break;
            case INTEGER : 
                q -> data.integer_data = ls -> data.integer_data;
                break;
            case CHAR : 
                q -> data.char_data = ls -> data.char_data;
                break;
            case LIST :
                q -> data.dlink = Copy(ls -> data.dlink);
                break;
        }
        q -> link = Copy(ls -> link);
    }
    return q;
}
int GenList::Equal(GenListNode * s, GenListNode * t){
    int x;
    if(s -> link == NULL && t -> link == NULL){
        return 1;
    }
    if(s -> link != NULL && t -> link != NULL && s -> link -> tag == t -> link -> tag){
        if(s -> link -> tag == INTEGER)
            if(s -> link -> data.integer_data == t -> link -> data.integer_data)
                x = 1;
            else x = 0;
        else if(s -> link -> tag == CHAR)
            if(s -> link -> data.char_data == t -> link -> data.char_data)
                x = 1;
            else x = 0;
        else x = Equal(s -> data.dlink, t -> data.dlink);
        return Equal(s -> link, t -> link);
    }
    return 0;
}

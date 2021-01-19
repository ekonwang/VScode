#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include<iostream>
using namespace std;
template <class NameType>
struct node{
    NameType data;
    node * link;
    node<NameType> (NameType val): data(val), link(NULL){};
};

template<class NameType>
class SeqList{
public:
    node * head;
    SeqList(){};
};

#endif  //_SEQLIST_H_
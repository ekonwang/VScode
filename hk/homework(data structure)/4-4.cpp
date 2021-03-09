#include<iostream>
using namespace std;

template <class T> struct Node{    //节点用结构体定义
    Node<T> *next;             
    T data;
};

template<class T> class LinkedPrQueue{
    Node<T>* head, *tail;                 //head, tail作为私有成员
public:
    LinkedPrQueue(){head = tail = NULL;}  //构造函数 
    bool push(T value){
        Node<T>* p = new Node<T>, *visitor = head, *before = NULL;         
        if(head == NULL) {
            head = p;
            tail = p;
            p -> next = NULL;
        }
        else{
            while( visitor != NULL ) {        // q != NULL && value > q -> data是有问题的
                T data = visitor -> data;
                if(value > data){
                    before = visitor;
                    visitor = visitor -> next;
               }
                else break;
            }               
            if(! before){
                p -> next = head;
                head = p;
            }
            else{
                p -> next = before -> next;
                before -> next = p;
                if(! visitor)
                    tail = p;
            }
        }
        p -> data = value;
        return true;
    }
    bool pop(T &reciever){
        if(! head)  return false;
        
        Node<T>* p = head; 
        reciever = head -> data;              
        head = head -> next;
        delete p;
        return true; 
    }
    void show(){
        Node<T>* p; 
        T value;
        p = head;
        cout << endl;
        while(p != NULL){
            value = p -> data;
            cout << value << '\t';
            p = p -> next;
        }
        cout << endl;
    }
};
   
void test(){               //测试程序
    LinkedPrQueue<int>* p = new LinkedPrQueue<int>();
    for(int i = 0; i < 10; i++){                     
        int value = i + 1;
        p -> push(value);
    }
    p -> show();   

    int valueAgain = 0;
    p -> push(valueAgain);
    p -> show();
    
    int receiver = 0;
    p -> pop(receiver);
    cout << endl << receiver << endl;
    p -> show();
}

int main(){
    test();
    system("pause");
    return 0;
}
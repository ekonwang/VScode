#include<iostream>
#include<string>

using namespace std;

template<class type> class nodelist;
template<class type> class node{
    friend class nodelist<type>;
    type value;
    node<type>* link;
public:
    node(type &v){value = v; link = NULL;}
    ~node(){}
};

template<class type> class nodelist{
    node<type>* head = NULL;
public:
    nodelist(){head = NULL;} //构造函数
    bool add(type &v){
        if (head == NULL) {head = new node<type>(v); return true;}
        else {
            node<type>* p = head;
            while ( p -> link != NULL ){p = p -> link;}
            p -> link = new node<type>(v);
            return true;
        }
    }
    bool remove(type &v){
        if ( head == NULL ){ return false; }
        else {
            node<type>* p = head, * before;
            while (p -> value != v && p != NULL){ 
                before = p; p = p -> link;}
            if ( p == head && p!= NULL) { head = p -> link; delete p; return true;}
            else { before -> link = p -> link; delete p; return true; }
            return false;
        }
    }
    bool find(type &v){
        if ( head == NULL ){ return false; }
        else {
            node<type>* p = head;
            while (p -> value != v && p != NULL){ 
                p = p -> link;}  
            if ( p == NULL) {  //如果此时p == NULL;程序会报错  //为什么是 ！=     ？？？？
                return false;}
            else return true;
            }
    }
    void printList(){
        if( head != NULL ){
            node<type>* p = head;
            while(p != NULL){
                cout << p -> value << " " ;
                p = p -> link;}
        }
    }
};

int main(){
    nodelist<int>* p = new nodelist<int>();
    string str ;
    int value = 0;
    while( true ){
        cin >> str;         //输入的数字也是字符
        if (str == "add"){ 
            cin >> value;
            if (p -> add(value)) cout << "true"<< endl;
            else cout << "false" << endl;
        }
        else if (str == "remove") { 
            cin >> value;
            if (p -> remove(value)) cout << "true" << endl;
            else cout << "false" << endl;
        }
        else if ( str == "find") {
            cin >> value;         //最开始少了cin >> value;
            if (p -> find(value)) cout << "true" << endl;
            else cout << "false" << endl;
        }
        else if (str == "printList") {
            p -> printList();
        }
        else cout << "error" << endl;
    } 
    system("pause");
    return 0;
}
//逻辑错误一抓一大把，要提高写代码解决问题的速度，并且养成模块化写代码的习惯，并提升准确率，减少代码中的语法错误和逻辑错误
#ifndef MYSTACK_H
#define MYSTACK_H
#define MaxN 100

template<class T> class mystack{
    T *s;
    int top;
public:
    mystack():top(-1),s(new T[MaxN]){}; //constructor
    mystack(int len):top(-1), s(new T[len]){};
    bool pop(){
        if (top == -1) return false;
        else top--; return true;
    }
    bool pop(T &receiver){
        if (top == -1) return false;
        else receiver = s[top--]; return true;
    }
    bool push(T &value){
        if (top == MaxN - 1) return false;
        else s[++top] = value;
    }
    T getTop(){
        if (top == -1) return NULL;
        return s[top--];
    }
    bool isEmpty(){
        if (top == -1) return true;
        else return false;
    }
};

#endif
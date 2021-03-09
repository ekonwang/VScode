#include<iostream>
using namespace std;
template <class Type> class CircleQueue{
    Type *q;
    int front, rear, tag, size;
public:
    CircleQueue(int maxSize){
        size = maxSize;
        q = new Type[size];
        front = rear = tag = 0;
    }
    int circle_enqueue(char x)
    {
        if(rear == front && tag == 1) return 1;
        rear = (rear + 1) % size;
        q[rear] = x;
        if(rear == front) tag = 1;
        return 0;
    }
    int circle_dequeue(Type *py){
        if(front == rear && tag == 0) return 1;
        front = (front + 1) % size;
        *py = q[front];
        if(tag) tag = 0;
        return 0;
    }
};
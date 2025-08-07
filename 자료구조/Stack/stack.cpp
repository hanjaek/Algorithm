#include <iostream>

using namespace std;

class Stack{
private:
    static const int MAX = 10000;
    int data[MAX];
    int top_idx;
    
public:
    Stack(){
        top_idx = -1;
    }

    void push(int x){
        if(top_idx < MAX - 1){
            data[++top_idx] = x;
        }
    }

    int pop(){
        if(!empty()){
            return data[top_idx--];
        }
        return -1;
    }

    int top(){
        if(!empty()){
            return data[top_idx];
        }
        return -1;
    }

    bool empty(){
        return top_idx == -1;
    }

    int size(){
        return top_idx + 1;
    }
};
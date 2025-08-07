#include <iostream>

using namespace std;

class Queue{
private:
    static const int MAX = 10000;
    int data[MAX];
    int front_idx;
    int back_idx;

public:
    Queue(){
        front_idx = 0;
        back_idx = 0;
    }

    void push(int x){
        if(back_idx < MAX){
            data[back_idx++] = x;
        }
    }

    int pop(){
        if(!empty()){
            return data[front_idx++];
        }
        return -1;
    }

    int front(){
        if(!empty()){
            return data[front_idx];
        }
        return -1;
    }

    int back(){
        if(!empty()){
            return data[back_idx -1];
        }
        return -1;
    }

    int size(){
        return back_idx - front_idx;
    }

    bool empty(){
        return front_idx == back_idx;
    }
};
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    private:
        vector<int> heap;

        void heapUp(int index){
            while (index > 0 && heap[parent(index)] < heap[index]){
                swap(heap[parent(index)], heap[index]);
                index = parent(index);
            }
        }

        void heapDown(int index){
            int left = leftChild(index);
            int right = rightChild(index);
            int largest = index;

            if(left < heap.size() && heap[left] > heap[largest]){
                largest = left;
            }
            if(right < heap.size() && heap[right] > heap[largest]){
                largest = right;
            }

            if(largest != index){
                swap(heap[index], heap[largest]);
                heapDown(largest);
            }
        }

        int parent(int i){return (i-1)/2;}
        int leftChild(int i){return 2*i + 1;}
        int rightChild(int i){return 2*i + 2;}

    public:
        void push(int number){
            heap.push_back(number);
            heapUp(heap.size()-1);
        }

        void pop(){
            if(heap.empty()){return;}

            heap[0] = heap.back();
            heap.pop_back();
            heapDown(0);
        }

        int top(){
            if(heap.empty()){return 0;}
            return heap[0];
        }

        bool empty(){
            return heap.empty();
        }
};

int repet;

void input(){
    cin >> repet;
}

void func(){

    MaxHeap heap;

    for(int i=0; i < repet; i++){
        int x, max;
        cin >> x;
        if(x == 0){
            max = heap.top();
            cout << max << "\n";
            heap.pop();
        }
        else{
            heap.push(x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
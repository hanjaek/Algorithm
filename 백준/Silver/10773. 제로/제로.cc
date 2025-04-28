#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> stack;
    int K;
    int number;
    int sum = 0;
    cin >> K;

    for(int i=0; i < K; i++){

        cin >> number;
        if(number != 0){
            stack.push_back(number);
        }
        else{
            if(!stack.empty()){
                stack.pop_back();
            }
        }
    }

    for(auto element : stack){
        sum += element;
    }

    cout << sum;

}
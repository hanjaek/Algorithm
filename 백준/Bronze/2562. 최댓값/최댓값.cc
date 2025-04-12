#include <iostream>

using namespace std;

pair<int, int> max(int *arr, int size){
    
    int max = 0;
    int idx;

    for(int i=0; i < size; i++){
        if(max < arr[i]){
            max = arr[i];
            idx = i+1;
        }
    }

    return {max, idx};
}

int main(){

    int numbers[9];
    
    for(int i=0; i<9; i++){
        cin >> numbers[i];
    }

    pair<int, int> result = max(numbers, 9);
    cout << result.first << "\n" << result.second;
}
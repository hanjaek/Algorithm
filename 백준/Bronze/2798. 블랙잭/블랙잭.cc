#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;
    int number;
    int result = 0;
    
    vector<int> numbers;
    
    for(int i=0; i < N; i++){
        cin >> number;
        numbers.push_back(number);
    }

    for(int i=0; i < N; i++){
        for(int j=i+1; j < N; j++){
            for(int k=j+1; k < N; k++){
                int sum = numbers[i] + numbers[j] + numbers[k];
                if((sum > result) && (sum <= M)){
                    result = sum;
                }
            }
        }
    }

    cout << result;

}
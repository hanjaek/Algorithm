#include <iostream>

using namespace std;

int main(){

    int N;
    int count[10000] = {0,};
    int number;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> number;
        count[number-1] += 1;
    }

    for(int j=0; j < 10000; j++){
        for(int k=0; k < count[j]; k++){
            cout << j+1 << "\n";
        }
    }
}
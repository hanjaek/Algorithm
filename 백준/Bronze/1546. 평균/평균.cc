#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    vector<double> score; 
    int number;
    int max = -1;
    double sum = 0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> number;
        score.push_back(number);
        if(max < number){
            max = number;
        }
    }

    for(int j=0; j<N; j++){
        sum += (score[j] / max) * 100;
    }

    cout << sum/N;
}
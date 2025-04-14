#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool isPrime(int number){
    for (int i=2; i <= sqrt(number); i++){
        if(number % i == 0){
            return false;
        }
    }

    return true;
}

int main(){

    unsigned short N;
    vector<int> numbers;
    int num;
    int cnt = 0;

    cin >> N;
    
    for(int i=0; i < N; i++){
        cin >> num;
        numbers.push_back(num);
    }

    for (int number : numbers){
        if(isPrime(number) && number != 1){
            cnt ++;
        }
    }

    cout << cnt;

}
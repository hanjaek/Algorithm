#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    unsigned n;
    string numbers;
    int sum = 0;

    cin >> n;
    cin >> numbers;

    for(int i=0; i < n; i++){
        sum += numbers[i] -'0';
    }

    cout << sum;

}
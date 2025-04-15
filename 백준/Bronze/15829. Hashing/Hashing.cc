#include <iostream>
#include <math.h>

using namespace std;

#define R 31

int main(){

    int L;
    string code;
    int hash_sum = 0;
    int number;

    cin >> L;
    cin >> code;

    for(int i=0; i < code.size(); i++){
        number = code[i] - 'a' + 1;
        // cout << number << " x " << pow(R,i) << " = " << number * pow(R, i) << endl;
        hash_sum += number * pow(R, i);
    }

    cout << hash_sum;
}
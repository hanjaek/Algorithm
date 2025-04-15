#include <iostream>
#include <math.h>

using namespace std;

#define R 31
#define MOD 1234567891

int main(){

    int L;
    string code;
    long long hash_sum = 0;
    long long number;
    long long r_pow = 1;

    cin >> L;
    cin >> code;

    for(int i=0; i < code.size(); i++){
        number = code[i] - 'a' + 1;
        // cout << number << " x " << pow(R,i) << " = " << number * pow(R, i) << endl;

        hash_sum = (hash_sum + (number * r_pow)) % MOD;
        r_pow = r_pow * R % MOD;
    }

    cout << hash_sum;
}
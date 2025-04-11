#include <iostream>

using namespace std;

long calc(long a, long b){

    return (a+b) * (a-b);

}

int main(){

    long a, b;
    long result;

    cin >> a >> b;
    result = calc(a, b);

    cout << result;
    
}
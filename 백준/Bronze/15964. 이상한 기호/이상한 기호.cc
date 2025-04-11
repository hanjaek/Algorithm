#include <iostream>

using namespace std;

int calc(unsigned a, unsigned b){

    return (a+b) * (a-b);

}

int main(){

    unsigned a, b;
    int result;

    cin >> a >> b;
    result = calc(a, b);

    cout << result;
    
}
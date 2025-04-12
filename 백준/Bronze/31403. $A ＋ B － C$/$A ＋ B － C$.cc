#include <iostream>
#include <string>

using namespace std;

int main(){

    int a, b, c;
    int up = 1;

    cin >> a;
    cin >> b;
    cin >> c;

    for(int i=0; i < to_string(b).size(); i++){
        up *= 10;
    }

    cout << a + b - c << "\n" << a*up + b - c ;
}
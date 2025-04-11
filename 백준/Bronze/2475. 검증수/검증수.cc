#include <iostream>
#include <sstream>

using namespace std;

int verification(int *arr, int size){

    int code = 0;

    for(int i=0; i<size; i++){
        code += arr[i]*arr[i];
    }

    return code % 10;
}

int main(){

    int codes[5];
    int code;
    string line;

    getline(cin, line);
    stringstream numbers(line);

    for(int i=0; i<5; i++){
        numbers >> codes[i];
    }

    code = verification(codes, 5);
    cout << code;
}
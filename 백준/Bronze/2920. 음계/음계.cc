#include <iostream>
#include <sstream>

using namespace std;

int main(){

    int arr[8];
    int asc = 0, des = 0;

    for(int i=0; i < 8; i++){
        cin >> arr[i];
    }

    for(int j=1; j <= 8; j++){

        if(arr[j-1] == j){
            asc++;
        }
        else if(arr[j-1] == 9-j){
            des++;
        }
    }

    if(asc == 8){
        cout << "ascending";
    }
    else if(des == 8){
        cout << "descending";
    }
    else{
        cout << "mixed";
    }
}
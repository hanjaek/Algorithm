#include <iostream>

using namespace std;

int main(){

    bool flag = true;
    int l, r;
    string numbers;

    while(1){

        string result = "yes";
        cin >> numbers;
        if(numbers == "0"){
            break;
        }

        l = 0;
        r = numbers.size() - 1;

        for(int i=0; i < numbers.size(); i++){
            if(l < r){
                if(numbers[l] != numbers[r]){
                    result = "no";
                }
                l++; r--;

                if(l==r){
                    break;
                }
            }
        }

        cout << result << "\n";

    }

}
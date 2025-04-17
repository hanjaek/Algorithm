#include <iostream>
#include <string>

using namespace std;

int fizz_buzz_1(string number[3]){
    
    int next_number;

    if(isdigit(number[0][0])){
        next_number = stoi(number[0]) + 3;
    }
    if(isdigit(number[1][0])){
        next_number = stoi(number[1]) + 2;
    }
    if(isdigit(number[2][0])){
        next_number = stoi(number[2]) + 1;
    }

    return next_number;

}

string fizz_buzz_2(int number){

    if(number % 15 == 0){
        return "FizzBuzz";
    }
    else if(number % 3 == 0){
        return "Fizz";
    }
    else if(number % 5 == 0){
        return "Buzz";
    }
    else{
        return to_string(number);
    }
}

int main(){

    string str[3];
    string result;

    for(int i=0; i < 3; i++){
        cin >> str[i];
    }

    int temp = fizz_buzz_1(str);
    result = fizz_buzz_2(temp);

    cout << result;
}
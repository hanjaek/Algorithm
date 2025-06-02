#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int number;

void input(){
    cin >> number;
    if(number==0){
        exit(0);
    }
}

void func(){
    int result = 2; // 시작과 끝 공백: 2로 시작
    string str = to_string(number);
    result += str.size() - 1; // 각 숫자사이 공백

    for(char element : str){
        if(element == '0'){
            result += 4;
        }
        else if(element == '1'){
            result += 2;
        }
        else{
            result += 3;
        }
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        input();
        func();
    }
}
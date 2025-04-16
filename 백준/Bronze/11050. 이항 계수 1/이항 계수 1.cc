#include <iostream>

using namespace std;

// 재귀 시간초과

// int fact(int number){

//     if(number == 1){
//         return 1;
//     }

//     return number * fact(number - 1);
// }

int fact(int number){

    int result = 1;

    for (int i=number; i >= 2; i--){
        result *= i;
    }

    return result;
}

int main(){
    
    // 이항계수 : nCk
    int N, K;
    
    cin >> N >> K;

    cout << fact(N) / (fact(N-K) * fact(K));
}
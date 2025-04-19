#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int N;
    int cnt = 0;
    int mult = 5;

    cin >> N;

    /*
        그냥 단순 팩토리얼 계산은 입력이 조금만 커져도 오버플로우
        0의 자리는 10이 몇개 생기는지 체크하면 됨
        10 = 2 x 5, but 2는 무수히 많이 생성됨 ex) 5! -> 5x4x3x2x1 -> 2:3번, 5:1번 짝수마다 2는 생성되므로 5의 개수만 알면 해결
        또 다른 문제) 25같은 경우는 5x5임 이를 카운트 해주기위해서 5의 배수로 나눠주면 됨. 
    */
    
    while(mult <= N){
        cnt += N / mult;
        mult *= 5;
    }

    cout << cnt;
}
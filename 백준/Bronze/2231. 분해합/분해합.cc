#include <iostream>

using namespace std;

int main(){

    int N;
    int result = 0;

    cin >> N;

    for(int i=1; i<N; i++){
        int sum = i;

        // j/10 은 자리수를 위함 ex) i=198일 때: 198 > 19 > 1 > 0
        for(int j=i; j != 0; j/=10){
            // sum 초기값 198, j도 198인데 %10 을하면 일의 자리 8, (198/10)-> 19 에서 %10하면 9, (19/10)-> 1에서 %10 하면 1
            sum += j % 10;
        }

        if(sum == N){
            result = i;
            break;
        }
    }

    cout << result;

}
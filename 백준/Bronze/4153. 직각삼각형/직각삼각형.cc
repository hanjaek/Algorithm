#include <iostream>

using namespace std;

int main(){

    while (1)
    {
        
        int arr[3];;
        int max = 0;

        cin >> arr[0] >> arr[1] >> arr[2];

        for(int i=0; i < 3; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }

        
        if((arr[0]==0) || (arr[1]==0) || (arr[2]==0)){
            break;
        }

        // pow 사용시 오차를 기재해야함
        if(arr[0]*arr[0] + arr[1]*arr[1] + arr[2]*arr[2] - max*max == max*max){
            cout << "right" << "\n";
        }
        else{
            cout << "wrong" << "\n";
        }

    }

    // a, b, c 중에서 어떤 값이 대각 값인지 모름.
    // 즉, 큰 값으로 지정해줘야함

    
}
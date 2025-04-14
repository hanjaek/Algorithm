#include <iostream>

using namespace std;

int main(){

    int N, T, P;
    int arr[6];
    int T_cnt = 0;

    cin >> N;
    for(int i=0; i < 6; i++){
        cin >> arr[i];
    }

    cin >> T >> P;

    for(int j=0; j < 6; j++){

        if(arr[j] % T == 0){
            T_cnt += arr[j] / T;
        }
        else{
            T_cnt += arr[j] / T + 1;
        }
    }

    cout << T_cnt << "\n" << N / P << " " << N % P;

}
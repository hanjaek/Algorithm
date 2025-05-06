#include <iostream>
#include <vector>

using namespace std;

int main(){

    int K, N; // K: 보유한 랜선 개수, N: 필요한 랜선 개수
    cin >> K >> N;

    vector<long long> L(K);
    long long max_len = 0;

    for(int i=0; i < K; i++){
        cin >> L[i];
        if(max_len < L[i]){
            max_len = L[i];
        }
    }

    long long left = 1;
    long long right = max_len;
    long long result = 0;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long cnt_lan = 0;

        for(int i=0; i < K; i++){
            cnt_lan += L[i] / mid;
        }

        // -1, +1 안하면 무한루프 걸리더라 (why) mid는 봤으니 더 늘려보자, 더 줄여보자
        if(cnt_lan >= N){
            result = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << result;
    
}
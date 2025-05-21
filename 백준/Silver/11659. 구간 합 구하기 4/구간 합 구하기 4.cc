#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N: 숫자 개수, M: 합 개수
    cin >> N >> M;

    vector<int> arr(N);
    vector<long long> sum(N+1,0);

    for(int i=0; i < N; i++){
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i]; 
    }

    for(int i=0; i < M; i++){
        int left, right;
        cin >> left >> right;
        cout << sum[right] - sum[left-1] << "\n";
    }

}
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;
vector<int> arr;

void input(){
    cin >> N;
    arr.resize(N);
    dp.resize(N, 0);

    for(int i=0; i < N; i++){
        cin >> arr[i];
    }
}

void func(){
    dp[0] = arr[0];
    int result = dp[0];

    for(int i=1; i < N; i++){
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        result = max(result, dp[i]);
    }

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}
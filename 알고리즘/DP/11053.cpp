#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, dp;

void input(){
    cin >> N;
    A.resize(N);
    dp.resize(N, 1);
    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    int result = 0;
    for(int i=0; i < N; i++){
        for(int j=0; j < i; j++){
            if(A[i] > A[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
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
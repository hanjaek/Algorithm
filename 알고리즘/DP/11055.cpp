#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> dp;

void input(){
    cin >> N;
    A.resize(N);
    dp.resize(N, 0);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    dp[0] = A[0];
    int result = dp[0];

    for(int i=1; i < N; i++){
        dp[i] = A[i];
        for(int j=0; j < i; j++){
            if(A[j] < A[i]){
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
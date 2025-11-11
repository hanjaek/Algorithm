#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000

int N, K;
vector<vector<int>> dp;

void input(){
    cin >> N >> K;
    dp.resize(K + 1, vector<int>(N + 1, 0));
}

void func(){
    // 숫자 하나로 n 만들기는 모두 1
    for(int n=0; n <= N; n++){
        dp[1][n] = 1; 
    }
    // k개로 0만드려면 모두 1
    for(int k=1; k <= K; k++){
        dp[k][0] = 1;
    }

    for(int k=2; k <= K; k++){
        for(int n=1; n <= N; n++){
            dp[k][n] = (dp[k][n-1] + dp[k-1][n]) % MOD;
        }
    }
    cout << dp[K][N] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
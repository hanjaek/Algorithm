#include <iostream>
#include <vector>

using namespace std;

#define MOD 10007

int N, K;
vector<vector<int>> dp;

void input(){
    cin >> N >> K;
    dp.resize(N+1, vector<int>(N+1, 0));
}

void func(){
    for(int n=0; n <= N; n++){
        dp[n][0] = 1;
        dp[n][n] = 1;
        for(int k=1; k < n; k++){
            dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % MOD;
        }
    }
    cout << dp[N][K] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
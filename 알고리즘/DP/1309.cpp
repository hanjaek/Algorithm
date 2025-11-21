#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> dp;
const int MOD = 9901;

void input() {
    cin >> N;
    dp.assign(N + 1, vector<int>(3, 0));
}

void func() {
    dp[1][0] = 1; 
    dp[1][1] = 1;
    dp[1][2] = 1; 

    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }

    int result = (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
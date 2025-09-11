#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000

int n;
vector<vector<long long>> dp;

void input(){
    cin >> n;
    dp.resize(n+1, vector<long long>(10, 0));
}

void func(){
    long long result = 0;

    // 첫자리는 모두 1계단
    for(int j=1; j <= 9; j++) dp[1][j] = 1;

    for(int i=2; i <= n; i++){
        dp[i][0] = dp[i-1][1] % MOD;
        
        for(int j=1; j <= 8; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD; 
        }
        dp[i][9] = dp[i-1][8] % MOD;
    }

    for(int j=0; j <= 9; j++){
        result = (result + dp[n][j]) % MOD;
    }

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
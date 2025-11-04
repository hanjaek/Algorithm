#include <iostream>
#include <vector>

using namespace std;

#define MOD 10007

int N;
// dp[자릿수][끝자리 숫자]
vector<vector<int>> dp;

void input(){
    cin >> N;
    dp.resize(N+1, vector<int>(10, 0));
}

void func(){
    int result = 0;

    for(int end=0; end <= 9; end++){
        dp[1][end] = 1;
    }

    for(int n=2; n <= N; n++){
        dp[n][0] = 1; // 0으로 끝나는 경우는 모든 자릿수가 0인 경우밖에 없음 
        for(int end = 1; end <= 9; end++){
            dp[n][end] = (dp[n][end-1] + dp[n-1][end]) % MOD;
        }
    }

    for(int end=0; end <= 9; end++){
        result =(result + dp[N][end]) % MOD;
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
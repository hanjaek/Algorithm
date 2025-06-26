#include <iostream>

using namespace std;

int T, N, M;

void input(){
    cin >> N >> M;
}

// long long fact(int n){
//     long long result = 1;
//     for(int i=2; i <= n; i++){
//         result *= i;
//     }
//     return result;
// }

void func(){
    // 조합 nCr = n-1Cr-1 + n-1Cr
    long long dp[31][31] = {0};
    for(int i=0; i <= 30; i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    cout << dp[M][N] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        input();
        func();
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n;
vector<vector<int>> sticker;
vector<vector<int>> dp;

void input(){
    cin >> n;
    sticker.assign(2, vector<int>(n));
    dp.assign(n, vector<int>(3, 0));

    for(int i=0; i < n; i++){
        cin >> sticker[0][i];
    }
    for(int i=0; i < n; i++){
        cin >> sticker[1][i];
    }
}

void func(){
    // 0: X, 1: 위, 2: 아래
    dp[0][0] = 0;
    dp[0][1] = sticker[0][0];
    dp[0][2] = sticker[1][0];

    for(int i=1; i < n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[0][i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + sticker[1][i];
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
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
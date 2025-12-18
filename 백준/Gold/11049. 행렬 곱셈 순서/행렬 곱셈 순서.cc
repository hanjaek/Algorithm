#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int ,int>> m;
vector<vector<int>> dp;

void input(){
    cin >> N;
    m.resize(N);
    // 길이가 1인 구간은 0
    dp.resize(N, vector<int>(N, 0)); 

    for(int i=0; i < N; i++){
        cin >> m[i].first >> m[i].second;
    }
}

void func(){
    for(int len=2; len <= N; len++){
        for(int i=0; i + len -1 < N; i++){
            int j = i + len - 1;
            dp[i][j] = 1e9;

            for(int k=i; k < j; k++){
                int cost = dp[i][k] + dp[k+1][j] + m[i].first * m[k].second * m[j].second;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << dp[0][N-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
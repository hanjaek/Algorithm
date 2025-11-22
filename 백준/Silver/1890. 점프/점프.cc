#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<long long>> dp;

void input(){
    cin >> N;
    grid.resize(N, vector<int>(N));
    dp.resize(N, vector<long long>(N, 0));

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

void func(){
    dp[0][0] = 1;

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            if(dp[y][x] == 0) continue;
            if(y == N-1 && x == N-1) continue;

            int jump_cnt = grid[y][x];
            int nx = x + jump_cnt;
            int ny = y + jump_cnt;

            if(nx < N) dp[y][nx] += dp[y][x];
            if(ny < N) dp[ny][x] += dp[y][x];
        }
    }
    cout << dp[N-1][N-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
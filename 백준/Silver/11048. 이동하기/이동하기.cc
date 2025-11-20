#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<int>> dp;

void input(){
    cin >> N >> M;
    grid.resize(N+1, vector<int>(M+1));
    dp.resize(N+1, vector<int>(M+1, 0));

    for(int y=1; y <= N; y++){
        for(int x=1; x <= M; x++){
            cin >> grid[y][x];
        }
    }
}

void func(){
    for(int y=1; y <= N; y++){
        for(int x=1; x <= M; x++){
            dp[y][x] = max({dp[y-1][x], dp[y][x-1], dp[y-1][x-1]}) + grid[y][x];
        }
    }
    cout<< dp[N][M] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
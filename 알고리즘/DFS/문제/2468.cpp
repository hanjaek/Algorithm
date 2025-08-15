#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, max_h;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));
    max_h = 0;

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
            max_h = max(max_h, grid[y][x]);
        }
    }
}

void dfs(int x, int y, int h){
    visited[y][x] = true;

    for(int dir=0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(!visited[ny][nx] && grid[ny][nx] > h){
            dfs(nx, ny, h);
        }
    }
}

void func(){
    int result = 0;
    for(int h=0; h <= max_h; h++){
        visited.assign(N, vector<bool>(N, false));
        int cnt = 0;

        for(int y=0; y < N; y++){
            for(int x=0; x < N; x++){
                if(!visited[y][x] && grid[y][x] > h){
                    cnt++;
                    dfs(x, y, h);
                }
            }
        }
        result = max(result, cnt);
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void input(){
    cin >> M >> N;
    grid.resize(M, vector<int>(N));
    visited.resize(M, vector<bool>(N, false));

    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

void bfs(int sx, int sy){
    queue<pair<int ,int>> q;
    q.push({sx, sy});
    visited[sy][sx] = true;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        for(int d=0; d < 8; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(!visited[ny][nx] && grid[ny][nx] == 1){
                q.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
}

void func(){
    int cnt = 0;

    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            if(!visited[y][x] && grid[y][x] == 1){
                bfs(x, y);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
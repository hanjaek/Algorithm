#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M >> K;
    grid.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<bool>(M, false));

    for(int i=0; i < K; i++){
        int r, c;
        cin >> r >> c;
        r--; c--;
        grid[r][c] = 1;
    }
}

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    int cnt = 1;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(!visited[ny][nx] && grid[ny][nx] == 1){
                q.push({nx, ny});
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

void func(){
    int result = 0;
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            if(!visited[y][x] && grid[y][x] == 1){
                result = max(result, bfs(x, y));
            }
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
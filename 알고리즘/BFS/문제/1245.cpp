#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
        }
    }
}

bool bfs(int sx, int sy){
    queue<pair<int ,int>> q;
    q.push({sx, sy});
    visited[sy][sx] = true;
    bool is_highest = true;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        for(int d=0; d < 8; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(grid[ny][nx] > grid[cy][cx]){
                is_highest = false;
            }
            // 헷갈렸던 부분: 인접한 같은 높이의 봉우리는 모두 함께 취급
            if(!visited[ny][nx] && grid[ny][nx] == grid[cy][cx]){
                q.push({nx, ny});
                visited[ny][nx] =true;
            }
        }
    }
    return is_highest;
}

void func(){
    int result = 0;

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            if(!visited[y][x]){
                if(bfs(x, y)){
                    result++;
                }
            }
        }
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> melt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(!visited[ny][nx] && grid[ny][nx] != 0){
                q.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
}

void func(){
    int years = 0;

    while(true){
        visited.assign(N, vector<bool>(M, false));
        int land = 0;

        for(int y=1; y < N-1; y++){
            for(int x=1; x < M-1; x++){
                if(!visited[y][x] && grid[y][x] != 0){
                    bfs(x, y);
                    land++;
                }
            }
        }
        if(land >= 2){
            cout << years;
            return;
        }
        if(land == 0){
            cout << 0;
            return;
        }

        melt.assign(N, vector<int>(M, 0));

        for(int y=1; y < N-1; y++){
            for(int x=1; x < M-1; x++){
                if(grid[y][x] == 0) continue;
                int cnt = 0;
                
                for(int dir=0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                    if(grid[ny][nx] == 0) cnt++;
                }
                melt[y][x] = cnt;
            }
        }

        for(int y=1; y < N-1; y++){
            for(int x=0; x < M-1; x++){
                if(grid[y][x] > 0){
                    grid[y][x] -= melt[y][x];
                    if(grid[y][x] < 0){
                        grid[y][x] = 0;
                    }
                }
            }
        }
        years++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
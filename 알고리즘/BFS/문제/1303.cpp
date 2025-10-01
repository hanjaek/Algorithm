#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<string> grid;
vector<vector<bool>> visited;
int power[2] = {0};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;
    grid.resize(M);
    visited.resize(M, vector<bool>(N, false));

    for(int y=0; y < M; y++){
        cin >> grid[y];
    }
}

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    char soldier = grid[y][x];
    int cnt = 1;

    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0|| ny < 0 || nx >= N || ny >= M) continue;
            if(!visited[ny][nx] && grid[ny][nx] == soldier){
                q.push({nx, ny});
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

void func(){
    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            if(!visited[y][x]){
                int cnt = bfs(x, y);
                if(grid[y][x] == 'W'){
                    power[0] += cnt * cnt;
                }
                else{
                    power[1] += cnt * cnt;
                }
            }
        }
    }

    cout << power[0] << " " << power[1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
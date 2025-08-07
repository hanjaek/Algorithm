#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<int>> grid;
vector<vector<int>> dist;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> M >> N;
    grid.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, 0));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
        }
    }
}

void bfs(){
    queue<pair<int, int>> q;
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            if(grid[y][x] == 1){
                q.push({x, y});
            }
        }
    }

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(grid[ny][nx] == 0){
                grid[ny][nx] = 1;
                q.push({nx, ny});

                dist[ny][nx] = dist[cy][cx] + 1;
            }
        }
    }
}

void func(){
    bfs();

    int max_day = 0;
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            if(grid[y][x] == 0){
                cout << -1;
                return;
            }
            max_day = max(max_day, dist[y][x]);
        }
    }

    cout << max_day;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
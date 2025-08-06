#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<char>> grid;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> M >> N;
    grid.resize(M, vector<char>(N));

    for(int y=0; y < M; y++){
        for(int x=0; x < N;x++){
            cin >> grid[y][x];
        }
    }
}

int bfs(int x, int y){
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    vector<vector<int>> dist(M, vector<int>(N, 0));
    int max_dist = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(!visited[ny][nx] && grid[ny][nx] == 'L'){
                visited[ny][nx] = true;
                q.push({nx, ny});

                dist[ny][nx] = dist[cy][cx] + 1;
                max_dist = max(max_dist, dist[ny][nx]);
            }
        }
    }
    return max_dist;
}

void func(){
    int max_dist = 0;

    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            if(grid[y][x] == 'L'){
                int dist = bfs(x, y);
                max_dist = max(max_dist, dist);
            }
        }
    }

    cout << max_dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
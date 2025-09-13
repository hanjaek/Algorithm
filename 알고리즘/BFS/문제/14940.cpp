#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, sx, sy;
vector<vector<int>> grid;
vector<vector<int>> dist;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m, -1));

    for(int y=0; y < n; y++){
        for(int x =0; x < m; x++){
            cin >> grid[y][x];
            if(grid[y][x]==2){
                sx = x; sy = y;
            }
        }
    }
}

void bfs(){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sy][sx] = 0;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(grid[ny][nx] != 0 && dist[ny][nx] == -1){
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void func(){
    bfs();

    for(int y=0; y < n; y++){
        for(int x=0; x < m; x++){
            if(grid[y][x] == 0){
                cout << 0;
            }
            else if(dist[y][x] == -1){
                cout << -1;
            }
            else{
                cout << dist[y][x];
            }
            if(x+1 < m){
                cout << ' ';
            }
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
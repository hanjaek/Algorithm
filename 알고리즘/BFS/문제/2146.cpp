#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<int>> land;
vector<vector<int>> dist;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N;
    grid.resize(N, vector<int>(N));
    land.resize(N, vector<int>(N, 0));
    dist.resize(N, vector<int>(N, -1));

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

void bfs_land_label(int sx, int sy, int land_id){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    land[sy][sx] = land_id;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(land[ny][nx] != 0 || grid[ny][nx] == 0) continue;

            land[ny][nx] = land_id;
            q.push({nx, ny});
        }
    }
}

int bfs_bridge(int land_id){
    dist.assign(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    int result = 1e9;

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            if(land[y][x] == land_id){
                q.push({x, y});
                dist[y][x] = 0;
            }
        }
    }

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
           
            if(land[ny][nx] != 0 && land[ny][nx] != land_id){
                result = min(result, dist[cy][cx]);
            }
            else if(land[ny][nx] == 0 && dist[ny][nx] == -1){
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({nx, ny});
            }
        }
    }
    return result;
}

void func(){
    int land_id = 0;
    int result = 1e9;

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            if(grid[y][x] == 1 && land[y][x] == 0){
                land_id++;
                bfs_land_label(x, y, land_id);
            }
        }
    }

    for(int id=1; id <= land_id; id++){
        result = min(result, bfs_bridge(id));
    }
    
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
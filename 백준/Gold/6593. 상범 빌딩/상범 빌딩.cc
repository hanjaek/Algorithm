#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int L, R, C;
vector<vector<string>> grid;
vector<vector<vector<int>>> dist;
int sx, sy, sz, ex, ey, ez;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

bool input(){
    if(!(cin >> L >> R >> C)) return false;
    if(L==0 && R==0 && C==0) return false;

    grid.assign(L, vector<string>(R));
    dist.assign(L, vector<vector<int>>(R, vector<int>(C, -1)));

    for(int z=0; z < L; z++){
        for(int y=0; y < R; y++){
            cin >> grid[z][y];

            for(int x=0; x < C; x++){
                if(grid[z][y][x] == 'S'){
                    sx = x; sy = y; sz = z;
                }
                if(grid[z][y][x] == 'E'){
                    ex = x; ey = y; ez = z;
                }
            }
        }
    }
    return true;
}

int bfs(int x, int y, int z){
    queue<tuple<int, int, int>> q;
    q.push({x, y, z});
    dist[z][y][x] = 0;

    while(!q.empty()){
        auto [cx, cy, cz] = q.front();
        q.pop();
        if(cx == ex && cy == ey && cz == ez){
            return dist[cz][cy][cx];
        }
        
        for(int dir=0; dir < 6; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nz = cz + dz[dir];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L) continue;
            if(grid[nz][ny][nx] != '#' && dist[nz][ny][nx] == -1){
                q.push({nx, ny, nz});
                dist[nz][ny][nx] = dist[cz][cy][cx] + 1;
            }
        }
    }

    return -1;
}

void func(){
    int minute = bfs(sx, sy, sz);

    if(minute == -1){
        cout << "Trapped!\n";
    } 
    else{
        cout << "Escaped in " << minute << " minute(s).\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(input()){
        func();
    }
}
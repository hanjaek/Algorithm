#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<string> grid;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> R >> C;
    grid.resize(R);
    
    for(int y=0; y < R; y++){
        cin >> grid[y];
    }
}

int bfs(){
    vector<vector<int>> water(R, vector<int>(C, -1));
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> water_q;
    queue<pair<int, int>> q;

    int Sx, Sy;

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            if(grid[y][x] == '*'){
                water[y][x] = 0;
                water_q.push({x, y});
            }
            else if(grid[y][x] == 'S'){
                Sx = x; Sy = y;
            }
        }
    }

    while(!water_q.empty()){
        auto [cx, cy] = water_q.front();
        water_q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
            if(grid[ny][nx] == 'X' || grid[ny][nx] == 'D') continue;
            if(water[ny][nx] != -1) continue;

            water[ny][nx] = water[cy][cx] + 1;
            water_q.push({nx, ny});
        }
    }

    dist[Sy][Sx] = 0;
    q.push({Sx, Sy});

    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        if(grid[cy][cx] == 'D') return dist[cy][cx];

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
            if(grid[ny][nx] == 'X') continue;
            if(dist[ny][nx] != -1) continue;

            int nt = dist[cy][cx] + 1;

            if(grid[ny][nx] == 'D'){
                dist[ny][nx] = nt;
                q.push({nx, ny});
            }
            else{
                if(water[ny][nx] == -1 || water[ny][nx] > nt){
                    dist[ny][nx] = nt;
                    q.push({nx, ny});
                }
            }

        }
    }
    return -1;
}

void func(){
    int result = bfs();

    if(result == -1){
        cout << "KAKTUS";
    }
    else{
        cout << result;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
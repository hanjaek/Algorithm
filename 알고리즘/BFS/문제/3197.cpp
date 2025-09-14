#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
vector<string> grid;
pair<int, int> swans[2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> R >> C;
    grid.resize(R);
    int idx = 0;

    for(int y=0; y < R; y++){
        cin >> grid[y];
        for(int x =0; x < C; x++){
            if(grid[y][x] == 'L') swans[idx++] = {x, y};
        }
    }
}

int bfs(){
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<pair<int, int>> swan_q, swan_next;
    queue<pair<int, int>> water_q, water_next;
    int days = 0;

    swan_q.push(swans[0]);
    visited[swans[0].second][swans[0].first] = true;

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            if(grid[y][x] != 'X') water_q.push({x, y});
        }
    }

    while(true){
        while(!swan_q.empty()){
            auto [cx, cy] = swan_q.front(); swan_q.pop();
            for(int dir=0; dir < 4; dir++){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
                if(!visited[ny][nx]){
                    if(nx == swans[1].first && ny == swans[1].second){
                        return days;
                    }
                    
                    visited[ny][nx] = true;
                    if(grid[ny][nx] != 'X'){
                        swan_q.push({nx, ny});
                    }
                    else{
                        swan_next.push({nx, ny});
                    }
                }
            }
        }

        while(!water_q.empty()){
            auto [cx, cy] = water_q.front(); water_q.pop();
            for(int dir=0; dir < 4; dir++){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
                if(grid[ny][nx] == 'X'){
                    grid[ny][nx] = '.';
                    water_next.push({nx, ny});
                }
            }
        }

        swap(swan_q, swan_next);
        swap(water_q, water_next);

        while (!swan_next.empty()) swan_next.pop();
        while (!water_next.empty()) water_next.pop();

        days++;
    }
}

void func(){
    cout << bfs();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
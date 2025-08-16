#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int row, col;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> row >> col;
    grid.resize(row, vector<int>(col));
    visited.resize(row, vector<bool>(col, false));

    for(int y=0; y < row; y++){
        for(int x=0; x < col; x++){
            cin >> grid[y][x];
        }
    }
}

int bfs(){
    visited.assign(row, vector<bool>(col, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= col || ny >= row) continue;
            if(!visited[ny][nx]){
                if(grid[ny][nx] == 0){
                    visited[ny][nx] = true;
                    q.push({nx, ny});
                }else if(grid[ny][nx] == 1){
                    visited[ny][nx] = true;
                    grid[ny][nx] = 2;
                }
            }
        }
    }

    int melted = 0;
    for(int y=0; y < row; y++){
        for(int x=0; x < col; x++){
            if(grid[y][x] == 2){
                grid[y][x] = 0;
                melted++;
            }
        }
    }
    return melted;
}

void func(){
    int hours = 0;
    int last = 0;
    
    while(true){
        int melted = bfs();
        if(melted == 0) break;
        hours++;
        last = melted;
    }

    cout << hours << "\n" << last;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
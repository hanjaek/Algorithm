#include <iostream>
#include <vector>

using namespace std;

int w, h;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(){
    cin >> w >> h;

    grid.clear(); visited.clear();
    grid.resize(h, vector<int>(w));
    visited.resize(h, vector<bool>(w, false));

    for(int y=0; y < h; y++){
        for(int x=0; x < w; x++){
            cin >> grid[y][x];
        }
    }
}

void dfs(int x, int y){
    visited[y][x] = true;

    for(int dir=0; dir < 8; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if(!visited[ny][nx] && grid[ny][nx] == 1){
            dfs(nx, ny);
        }
    }
}

void func(){
    int cnt = 0;

    for(int y=0; y < h; y++){
        for(int x=0; x < w; x++){
            if(!visited[y][x] && grid[y][x] == 1){
                dfs(x, y);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        input();
        if (w == 0 && h == 0) break;
        func();
    }
}
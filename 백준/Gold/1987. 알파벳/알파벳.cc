#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
vector<vector<char>> grid;
bool visited[26];
int max_depth = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> R >> C;
    grid.resize(R, vector<char>(C));

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            cin >> grid[y][x];
        }
    }
}

void dfs(int x, int y, int depth){
    max_depth = max(max_depth, depth);
    visited[grid[y][x] - 'A'] = true;

    for(int dir=0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
        if(!visited[grid[ny][nx] - 'A']){
            dfs(nx, ny, depth + 1);
        }
    }
    visited[grid[y][x] - 'A'] = false;
}

void func(){
    dfs(0, 0, 1);
    cout << max_depth;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
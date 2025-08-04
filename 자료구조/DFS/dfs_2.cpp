#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            cin >> grid[i][j];
        }
    }
}

void dfs(int x, int y){
    visited[x][y] = true;

    for(int dir=0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(!visited[nx][ny] && grid[nx][ny] == 1){
            dfs(nx, ny);
        }
    }
}

void func(){
    int cnt = 0;

    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            if(!visited[i][j] && grid[i][j]==1){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << "count: " << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
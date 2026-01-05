#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int result = 0;

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
        }
    }
}

void dfs(int x, int y, int depth, int sum){
    visited[y][x] = true;

    if(depth == 4){
        result = max(result, sum);
        visited[y][x] = false;
        return;
    }

    for(int dir=0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(visited[ny][nx]) continue;

        dfs(nx, ny, depth + 1, sum + grid[ny][nx]);
    }
    visited[y][x] = false;
}

void check_T(int x, int y){
    int center = grid[y][x];

    for(int i=0; i < 4; i++){
        int sum = center;
        int cnt = 1;

        for(int dir=0; dir < 4; dir++){
            if(dir == i) continue; // 중심으로부터 3개의 블록만

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) break;

            cnt++;
            sum += grid[ny][nx];
        }
        if(cnt == 4) result = max(result, sum);
    }
}

void func(){
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            dfs(x, y, 1, grid[y][x]);
            check_T(x, y);
        }
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
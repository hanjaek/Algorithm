#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<int> areas;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void fill_grid(int x1, int y1, int x2, int y2){
    for(int y=y1; y < y2; y++){
        for(int x=x1; x < x2; x++){
            grid[y][x] = 1;
        }
    }
}

void input(){
    cin >> M >> N >> K;
    grid.resize(M, vector<int>(N));
    visited.resize(M, vector<bool>(N, false));

    for(int i=0; i < K; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fill_grid(x1, y1, x2, y2);
    }
}

int dfs(int x, int y){
    visited[y][x] = true;
    int cnt = 1;

    for(int dir=0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(!visited[ny][nx] && grid[ny][nx]==0){
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

void func(){
    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            if(!visited[y][x] && grid[y][x]==0){
                int area_cnt = dfs(x, y);
                areas.push_back(area_cnt);
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << areas.size() << "\n";
    for(int area : areas) cout << area << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for(int y=0; y < n; y++){
        for(int x=0; x < m; x++){
            cin >> grid[y][x];
        }
    }
}

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    int cnt = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(!visited[ny][nx] && grid[ny][nx] == 1){
                q.push({nx, ny});
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

void func(){
    int areas = 0;
    int max_cnt = 0;

    for(int y=0; y < n; y++){
        for(int x=0; x < m; x++){
            if(!visited[y][x] && grid[y][x] == 1){
                int cnt = bfs(x, y);
                max_cnt = max(max_cnt, cnt);
                areas++;
            }
        }
    }

    cout << areas << "\n" << max_cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
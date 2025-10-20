#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 빈공간: . ; 울타리 : # ; 늑대: v ; 양: k
int R, C;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> R >> C;
    grid.resize(R);
    visited.resize(R, vector<bool>(C, false));

    for(int y=0; y < R; y++){
        cin >> grid[y];
    }
}

pair<int ,int> bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sy][sx] = true;
    int v_cnt = 0, k_cnt = 0;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        if(grid[cy][cx] == 'v'){
            v_cnt++;
        }
        else if(grid[cy][cx] == 'k'){
            k_cnt++;
        }
        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
            if(!visited[ny][nx] && grid[ny][nx] != '#'){
                q.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
    return {v_cnt, k_cnt};
}

void func(){
    int v_total = 0, k_total = 0;

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            if(!visited[y][x] && grid[y][x] != '#'){
                auto [v_cnt, k_cnt] = bfs(x, y);
                if(v_cnt >= k_cnt){
                    v_total += v_cnt;
                }
                else{
                    k_total += k_cnt;
                }
            }
        }
    }
    cout << k_total << " " << v_total << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
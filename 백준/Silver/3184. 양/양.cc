#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

pair<int, int> bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    int cnt_o = 0, cnt_v = 0;

    if(grid[y][x] == 'o'){
        cnt_o++;
    }
    else if(grid[y][x] == 'v'){
        cnt_v++;
    }

    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
            if(visited[ny][nx] || grid[ny][nx] == '#') continue;

            q.push({nx, ny});
            visited[ny][nx] = true;
            if(grid[ny][nx] == 'o'){
                cnt_o++;
            }
            else if(grid[ny][nx] == 'v'){
                cnt_v++;
            }
        }
    }

    return {cnt_o, cnt_v};
}

void func(){
    int total_o = 0, total_v = 0;

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            if(!visited[y][x] && grid[y][x] != '#'){
                auto [o, v] = bfs(x, y);
                if(o > v){
                    total_o += o;
                }
                else{
                    total_v += v;
                }
            }
        }
    }
    cout << total_o << " " << total_v << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
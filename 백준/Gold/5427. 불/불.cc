#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, w, h;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> w >> h;
    grid.assign(h,"");
    visited.assign(h, vector<bool>(w, false));

    for(int y=0; y < h; y++){
        cin >> grid[y];
    }
}

int bfs(){
    queue<pair<int ,int>> fq;
    queue<pair<int ,int>> sq;
    int sec = 0;

    for(int y=0; y < h; y++){
        for(int x=0; x < w; x++){
            if(grid[y][x] == '*'){
                fq.push({x, y});
            }
            if(grid[y][x] == '@'){
                sq.push({x, y});
                visited[y][x] = true;
            }
        }
    }

    while(!sq.empty()){
        sec++;

        int fq_size = fq.size();
        int sq_size = sq.size();

        for(int i=0; i < fq_size; i++){
            auto [cx, cy] = fq.front();
            fq.pop();

            for(int d=0; d < 4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                if(grid[ny][nx] == '.' || grid[ny][nx] == '@'){
                    grid[ny][nx] = '*';
                    fq.push({nx, ny});
                }
            }
        }

        for(int i=0; i < sq_size; i++){
            auto [cx, cy] = sq.front();
            sq.pop();

            for(int d=0; d < 4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(nx < 0 || ny < 0 || nx >= w || ny >= h){
                    return sec;
                }

                if(grid[ny][nx] == '.' && !visited[ny][nx]){
                    sq.push({nx, ny});
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return -1;
}

void func(){
    int result = bfs();
    if(result == -1){
        cout << "IMPOSSIBLE" << "\n";
    }
    else{
        cout << result << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        input();
        func();
    }
}
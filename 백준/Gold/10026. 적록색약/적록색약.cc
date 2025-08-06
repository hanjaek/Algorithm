#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N;
    grid.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    char color = grid[y][x];

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(!visited[ny][nx] && grid[ny][nx] == color){
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
}

void func(){
    int ordinary = 0;
    int weakness = 0;

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            if(!visited[y][x]){
                bfs(x, y);
                ordinary++;
            }
        }
    }

    visited.assign(N, vector<bool>(N, false));
    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            if(grid[y][x] == 'G') grid[y][x]='R';
        }
    }
    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            if(!visited[y][x]){
                bfs(x, y);
                weakness++;
            }
        }
    }

    cout << ordinary << " " << weakness;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
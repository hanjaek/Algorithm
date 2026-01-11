#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, L, R;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int sum;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> L >> R;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

bool bfs(int sx, int sy){
    queue<pair<int ,int>> q;
    vector<pair<int, int>> colab;
    q.push({sx, sy});
    visited[sy][sx] = true;
    colab.push_back({sx, sy});

    sum = grid[sy][sx];
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visited[ny][nx]) continue;

            int diff = abs(grid[ny][nx] - grid[cy][cx]);
            if(L <= diff && diff <= R){
                q.push({nx, ny});
                colab.push_back({nx, ny});
                visited[ny][nx] = true;
                sum += grid[ny][nx];
            }
        }
    }

    if(colab.size() <= 1) return false;
    int avg = sum / colab.size();

    for(pair<int ,int> &p : colab){
        grid[p.second][p.first] = avg;
    }
    return true;
}

void func(){
    int days = 0;

    while(true){
        visited.assign(N, vector<bool>(N, false));
        bool moved = false;

        for(int y=0; y < N; y++){
            for(int x=0; x < N; x++){
                if(!visited[y][x]){
                    if(bfs(x, y)) moved = true;
                }
            }
        }
        if(!moved) break;
        days++;
    }

    cout << days << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
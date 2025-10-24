#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void input(){
    cin >> N;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

bool bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        int jump = grid[cy][cx];
        if(jump == -1) return true;

        for(int d=0; d < 2; d++){
            int nx = cx + dx[d] * jump;
            int ny = cy + dy[d] * jump;

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(!visited[ny][nx]){
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

void func(){
    cout << (bfs() ? "HaruHaru" : "Hing") << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int S, X, Y;
vector<vector<int>> grid;
vector<queue<pair<int, int>>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> K;
    grid.resize(N+1, vector<int>(N+1, 0));
    q.resize(K+1, queue<pair<int, int>>());

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            cin >> grid[y][x];
        }
    }
    cin >> S >> X >> Y;
}

void bfs(int v){
    int cur = q[v].size();

    while(cur--){
        auto [cx, cy] = q[v].front();
        q[v].pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(grid[ny][nx] == 0){
                grid[ny][nx] = v;
                q[v].push({nx, ny});
            }
        }
    }
}

void func(){
    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            if(grid[y][x] != 0){
                q[grid[y][x]].push({x, y});
            }
        }
    }

    for(int time=0; time < S; time++){
        for(int virus=1; virus <= K; virus++){
            bfs(virus);
        }
    }

    cout << grid[X][Y] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
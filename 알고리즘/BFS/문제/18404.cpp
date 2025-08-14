#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<int>> dist;
vector<pair<int, int>> enemy;
int Kx, Ky;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1}; 

void input(){
    cin >> N >> M;
    grid.resize(N+1, vector<int>(N+1, 0));
    dist.resize(N+1, vector<int>(N+1, -1));
    enemy.resize(M);

    cin >> Kx >> Ky;
    
    for(int i=0; i < M; i++){
        int x, y;
        cin >> x >> y;
        enemy[i] = {x, y};
    }
}

void bfs(){
    queue<pair<int, int>> q;
    q.push({Kx, Ky});
    dist[Ky][Kx] = 0;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        for(int dir=0; dir < 8; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[cy][cx] + 1;
            q.push({nx, ny});
            
        }
    }
}

void func(){
    bfs();
    for(int i=0; i < M; i++){
        auto [ex, ey] = enemy[i];
        cout << dist[ey][ex] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
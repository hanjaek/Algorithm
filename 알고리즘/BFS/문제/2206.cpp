#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
vector<string> grid;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;
    grid.resize(N);
    for(int y=0; y < N; y++){
        cin >> grid[y];
    }
}

int bfs(){
    vector<vector<pair<int,int>>> dist(N, vector<pair<int,int>>(M, {0,0}));
    queue<tuple<int, int, int>> q;
    
    if(grid[0][0] == '0'){
        dist[0][0].first = 1;
        q.push({0, 0, 0});
    }
    else{
        dist[0][0].second = 1;
        q.push({0, 0, 1});
    }


    while(!q.empty()){
        auto [x, y, block] = q.front();
        q.pop();
        int distance = (block == 0 ? dist[y][x].first : dist[y][x].second);
        if(x == M - 1 && y == N - 1) return distance;

        for(int dir=0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(grid[ny][nx] == '0'){
                if(block == 0 && dist[ny][nx].first == 0){
                    dist[ny][nx].first = distance + 1;
                    q.push({nx, ny, 0});
                }

                if(block == 1 && dist[ny][nx].second == 0 ){
                    dist[ny][nx].second = distance + 1;
                    q.push({nx, ny, 1});
                }
            }
            else{
                if(block == 0 && dist[ny][nx].second == 0){
                    dist[ny][nx].second = distance + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    return -1;
}

void func(){
    int dist = bfs();
    cout << dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
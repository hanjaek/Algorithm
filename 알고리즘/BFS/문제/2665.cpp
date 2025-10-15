#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
vector<string> grid;
vector<vector<int>> dist;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N;
    grid.resize(N);
    dist.resize(N, vector<int>(N, 1e9));
    
    for(int i=0; i < N; i++){
        cin >> grid[i];
    }
}

void bfs(){
    deque<pair<int, int>> dq;
    dist[0][0] = 0;
    dq.push_front({0, 0});

    while(!dq.empty()){
        auto [cx, cy] = dq.front();
        dq.pop_front();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            int cost = (grid[ny][nx] == '0') ? 1: 0;
            if(dist[ny][nx] > dist[cy][cx] + cost){
                dist[ny][nx] = dist[cy][cx] + cost;
                if(cost == 0){
                    dq.push_front({nx, ny});
                }
                else{
                    dq.push_back({nx, ny});
                }
            }
        }
    }
}

void func(){
    bfs();
    cout << dist[N-1][N-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
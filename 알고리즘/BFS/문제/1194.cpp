#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int sx, sy;
vector<string> grid;
vector<vector<vector<int>>> dist;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;

    grid.resize(N);
    dist.resize(N, vector<vector<int>>(M, vector<int>(1 << 6, -1)));

    for(int y=0; y < N; y++){
        cin >> grid[y];
        for(int x=0; x < M; x++){
            if(grid[y][x] == '0'){
                sx = x; sy = y;
            }
        }
    }
}

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    dist[sy][sx][0] = 0;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cmask = q.front().second;
        q.pop();

        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            int nmask = cmask;

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            char next = grid[ny][nx];

            if(next == '#') continue;
            if(next == '1'){
                return dist[cy][cx][cmask] + 1;
            }
            if('a' <= next && next <= 'f'){
                nmask = cmask | (1 << (next - 'a'));
            }
            if('A' <= next && next <= 'F'){
                int need_key = 1 << (next - 'A');
                if((cmask & need_key) == 0) continue;
            }
            if(dist[ny][nx][nmask] != -1) continue;

            q.push({{nx, ny}, nmask});
            dist[ny][nx][nmask] = dist[cy][cx][cmask] + 1;
        }   
    }
    return -1;
}

void func(){
    cout << bfs() << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
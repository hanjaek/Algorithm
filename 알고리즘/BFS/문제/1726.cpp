#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int M, N;
vector<vector<int>> grid;
vector<vector<vector<int>>> dist;
int sx, sy, sd, ex, ey, ed;

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

int turn_left(int d){
    if(d == 1) return 4;
    if(d == 2) return 3;
    if(d == 3) return 1;
    return 2;
}

int turn_right(int d){
    if(d == 1) return 3;
    if(d == 2) return 4;
    if(d == 3) return 2;
    return 1;
}

void input(){
    cin >> M >> N;
    grid.resize(M, vector<int>(N));
    dist.resize(M, vector<vector<int>>(N, vector<int>(5, -1)));
    
    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }

    cin >> sy >> sx >> sd; sy--; sx--;
    cin >> ey >> ex >> ed; ey--; ex--;
}

int bfs(){
    queue<tuple<int, int, int>> q;
    dist[sy][sx][sd] = 0;
    q.push({sx, sy, sd});

    while(!q.empty()){
        auto [cx, cy, cd] = q.front(); q.pop();
        int cur_d = dist[cy][cx][cd];

        if(cx == ex && cy == ey && cd == ed) return cur_d;

        int ld = turn_left(cd);
        int rd = turn_right(cd);

        if(dist[cy][cx][ld] == -1){
            q.push({cx, cy, ld});
            dist[cy][cx][ld] = cur_d + 1;
        }
        if(dist[cy][cx][rd] == -1){
            q.push({cx, cy, rd});
            dist[cy][cx][rd] = cur_d + 1;
        }

        for(int k=1; k <=3; k++){
            int nx = cx + dx[cd]*k;
            int ny = cy + dy[cd]*k;

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if(grid[ny][nx] == 1) break;

            if(dist[ny][nx][cd] == -1){
                q.push({nx, ny, cd});
                dist[ny][nx][cd] = cur_d + 1;
            }
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
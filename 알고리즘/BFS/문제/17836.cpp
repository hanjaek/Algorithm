#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, T;
vector<vector<int>> grid;
vector<vector<int>> dist;
int gram_x, gram_y;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M >> T;
    grid.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, -1));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
            if(grid[y][x] == 2){
                gram_x = x; gram_y = y;
            }
        }
    }
}

int bfs(){
    queue<pair<int ,int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    int gram_x_dist;
    int gram_o_dist;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        
        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(dist[ny][nx] == -1 && grid[ny][nx] != 1){
                q.push({nx, ny});
                dist[ny][nx] = dist[cy][cx] + 1;
            }
        }
    }
    gram_x_dist = dist[N-1][M-1];
    gram_o_dist = 1e9;

    if(dist[gram_y][gram_x] != -1){
        int to_gram = dist[gram_y][gram_x];
        int from_gram = (N-1 - gram_y) + (M-1 - gram_x);
        gram_o_dist = to_gram + from_gram;
    }

    int result = 1e9;
    if(gram_x_dist != -1){
        result = min(result, gram_x_dist);
    }
    result = min(result, gram_o_dist);

    return result;
}

void func(){
    int result = bfs();
    if(result <= T){
        cout << result << "\n";
    }
    else{
        cout << "Fail\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
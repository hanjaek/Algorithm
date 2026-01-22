#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define endl "\n"
using namespace std;

int N, sx, sy;
vector<vector<int>> grid;
int shark_size = 2;
int cnt = 0;
int total_dist = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

tuple<int ,int ,int> bfs(){
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(N, -1));

    dist[sy][sx] = 0;
    q.push({sx, sy});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(grid[ny][nx] > shark_size) continue;
            if(dist[ny][nx] != -1) continue;

            q.push({nx, ny});
            dist[ny][nx] = dist[cy][cx] + 1;
        }
    }

    int min_dist = 1e9;
    int best_x = -1, best_y = -1;

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            if(dist[y][x] == -1) continue;
            if(0 < grid[y][x] && grid[y][x] < shark_size){
                if(min_dist > dist[y][x]){
                    min_dist = dist[y][x];
                    best_x = x; best_y = y;
                }
                else if(min_dist == dist[y][x]){
                    if(best_y > y || (best_y == y && best_x > x)){
                        best_x = x; best_y = y;
                    }
                }
            }
        }
    }
    return {best_x, best_y, min_dist};
}

void input(){
    cin >> N;
    grid.resize(N, vector<int>(N));

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
            if(grid[y][x] == 9){
                sx = x; sy = y;
                // 처리 빠졌었음
                grid[y][x] = 0;
            }
        }
    }
}

void func(){
    while(true){
        tuple<int, int, int> t = bfs();

        int cx = get<0>(t);
        int cy = get<1>(t);
        int c_dist = get<2>(t);

        if(c_dist == 1e9) break;
        sx = cx; sy = cy; total_dist += c_dist;
        cnt++;
        grid[sy][sx] = 0;

        if(cnt == shark_size){
            shark_size++;
            cnt = 0;
        }
    }
    cout << total_dist << endl;

    // for(int y=0; y < N; y++){
    //     for(int x=0; x <n; x++){
    //         cout << grid[y][x] << " ";
    //     }
    //     cout << endl;
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
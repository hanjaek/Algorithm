#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<int>> room;
vector<int> room_size;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int wall[4] = {1, 2, 4, 8};

void input(){
    cin >> N >> M;
    grid.resize(M, vector<int>(N));
    room.resize(M, vector<int>(N, -1));

    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

int bfs(int sx, int sy, int id){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    room[sy][sx] = id;
    int cnt = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        int cw = grid[cy][cx];

        for(int d=0; d < 4; d++){
            // 벽 체크
            if(cw & wall[d]) continue;

            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(room[ny][nx] != -1) continue;

            room[ny][nx] = id;
            cnt++;
            q.push({nx, ny});
        }
    }
    return cnt;
}

void func(){
    int room_cnt = 0;
    int room_max_cnt = 0;
    int best_merge = 0;

    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            if(room[y][x] == -1){
                int rs = bfs(x, y, room_cnt);
                room_size.push_back(rs);
                room_max_cnt = max(room_max_cnt, rs);
                room_cnt++;
            }
        }
    }
    for(int y=0; y < M; y++){
        for(int x=0; x < N; x++){
            for(int d=0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                // 벽이 있어야 제거할 수 있음
                if((grid[y][x] & wall[d]) == 0) continue;

                int cr = room[y][x];
                int nr = room[ny][nx];
                if(cr == nr) continue;

                best_merge = max(best_merge, room_size[cr] + room_size[nr]);
            }
        }
    }
    cout << room_cnt << "\n";
    cout << room_max_cnt << "\n";
    cout << best_merge << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
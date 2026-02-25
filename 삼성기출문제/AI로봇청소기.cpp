#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define endl "\n"

struct Robot{
    int y;
    int x;
    int dir;
};

int N, K, L;
vector<vector<int>> grid;
vector<vector<int>> robot_loc;
vector<Robot> robots;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool range_check(int y, int x){
    return (1<=x && x<=N && 1<=y && y<=N);
}

bool dust_check() {
    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            if(grid[y][x] > 0) return true;
        }
    }
    return false;
}

pair<int ,int> bfs(int robot_idx){
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N+1, vector<int>(N+1, -1));
    vector<pair<int, int>> moves;
    int best_dist = 1e9;

    int sy = robots[robot_idx].y;
    int sx = robots[robot_idx].x;

    if(grid[sy][sx] > 0) return {sy, sx};
    dist[sy][sx] = 0;
    q.push({sy, sx});

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        int cd = dist[cy][cx];

        if(cd > best_dist) break;

        if(grid[cy][cx] > 0 && robot_loc[cy][cx] == 0){
            best_dist = cd;
            moves.push_back({cy, cx});
            continue;
        }

        for(int dir=0; dir < 4; dir++){
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if(!range_check(ny, nx)) continue;
            if(dist[ny][nx] != -1 || grid[ny][nx] == -1 || robot_loc[ny][nx] != 0) continue;

            q.push({ny, nx});
            dist[ny][nx] = cd + 1;
        }
    }
    if(moves.empty()) return {-1, -1};
    sort(moves.begin(), moves.end());
    return moves[0];
}

void robot_move(){
    for(int i=0; i < K; i++){
        pair<int ,int> p = bfs(i);
        int ny = p.first; int nx = p.second;

        if(ny == -1 && nx == -1) continue;
        robot_loc[robots[i].y][robots[i].x] = 0;
        robots[i].y = ny; robots[i].x = nx;
        robot_loc[ny][nx] = i + 1;
    }
}

int clean_check(int y, int x, int ridx){
    if(!range_check(y, x)) return 0;
    if(grid[y][x] <= 0) return 0;
    return min(20, grid[y][x]);
}

void clean_apply(int y, int x, int ridx){
    if(!range_check(y, x)) return;
    if(grid[y][x] <= 0) return;
    grid[y][x] -= min(20, grid[y][x]);
}

void vaccum(){
    int priority[4] = {1, 2, 3, 0};

    for(int i=0; i < K; i++){
        int y = robots[i].y;
        int x = robots[i].x;

        int best_sum = -1;
        int best_dir = robots[i].dir;

        for(int dir=0; dir < 4; dir++){
            int sum = 0;
            int fd = priority[dir];
            int ld = (fd + 3) % 4;
            int rd = (fd + 1) % 4;

            sum += clean_check(y, x, i);
            sum += clean_check(y + dy[ld], x + dx[ld], i);
            sum += clean_check(y + dy[fd], x + dx[fd], i);
            sum += clean_check(y + dy[rd], x + dx[rd], i);

            if(sum > best_sum){
                best_sum = sum;
                best_dir = fd;
            }
        }

        int selected_d = best_dir;
        int ld = (selected_d + 3) % 4;
        int rd = (selected_d + 1) % 4;

        clean_apply(y, x, i);
        clean_apply(y + dy[ld], x + dx[ld], i);
        clean_apply(y + dy[selected_d], x + dx[selected_d], i);
        clean_apply(y + dy[rd], x + dx[rd], i);
        robots[i].dir = best_dir;
    }
}

void dust_stack(){
    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            if(grid[y][x] > 0) grid[y][x] += 5;
        }
    }
}

void dust_diffusion(){
    vector<vector<int>> add_dust(N+1, vector<int>(N+1, 0));

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            if(grid[y][x] != 0) continue;

            int sum = 0;

            for(int dir=0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(!range_check(ny, nx)) continue;
                if(grid[ny][nx] > 0) sum += grid[ny][nx];
            }
            add_dust[y][x] = sum / 10;
        }
    }

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            if(grid[y][x] == 0){
                grid[y][x] += add_dust[y][x];
            }
        }
    }
}

void input(){
    int r_x, r_y;
    cin >> N >> K >> L;
    grid.resize(N+1, vector<int>(N+1, 0));
    robot_loc.resize(N+1, vector<int>(N+1, 0));
    robots.resize(K);

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            cin >> grid[y][x];
        }
    }
    for(int i=0; i < K; i++){
        cin >> r_y >> r_x;
        robot_loc[r_y][r_x] = i + 1;
        robots[i] = {r_y, r_x, 0};
    }
}

void total_dust(){
    long long sum = 0;

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            if(grid[y][x] > 0){
                sum += grid[y][x];
            }
        }
    }

    cout << sum << endl;
}

void func(){
    if(!dust_check()){
        cout << 0 << endl;
        return;
    }

    for(int i=0; i < L; i++){
        robot_move();
        vaccum();
        dust_stack();
        dust_diffusion();
        total_dust();
    }
}

void test(){
    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
    return 0;
}
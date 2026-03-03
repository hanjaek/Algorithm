#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
#define endl "\n"

int R, C, K, W;
vector<vector<int>> grid;
vector<pair<int ,int>> targets;
vector<vector<vector<bool>>> walls;

// 1: 오, 2: 왼, 3: 위, 4: 아래 
int dc[5] = {0, 1, -1, 0, 0};
int dr[5] = {0, 0, 0, -1, 1};

// 기준별 대각선 방향 설정
int Ld[5] = {0, 3, 4, 2, 1};
int Rd[5] = {0, 4, 3, 1, 2};

struct Heater{
    int hr, hc, hdir;
};

vector<Heater> heaters;

bool check_range(int r, int c){
    return (0 <= r && r < R && 0 <= c && c < C);
}

bool check_k_value(){
    for(pair<int, int> p : targets){
        int r = p.first;
        int c = p.second;

        if(grid[r][c] < K) return false;
    }
    return true;
}

void padding_down(){
    for(int c=0; c < C; c++){
        grid[0][c] = max(0, grid[0][c] - 1);
        grid[R-1][c] = max(0, grid[R-1][c] - 1);
    }

    for(int r=1; r < R-1; r++){
        grid[r][0] = max(0, grid[r][0] - 1);
        grid[r][C-1] = max(0, grid[r][C-1] - 1);
    }
}

void adjust_temp(){
    vector<vector<int>> adjust(R, vector<int>(C, 0));

    for(int r=0; r < R; r++){
        for(int c=0; c < C; c++){
            int cur_temp = grid[r][c];

            for(int dir=1; dir <= 4; dir++){
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if(!check_range(nr, nc)) continue;
                if(walls[r][c][dir]) continue;

                int new_temp = grid[nr][nc];
                if(new_temp > cur_temp) continue;

                int diff = (cur_temp - new_temp) / 4;

                adjust[r][c] -= diff;
                adjust[nr][nc] += diff;
            }
        }
    }

    for(int r=0; r < R; r++){
        for(int c=0; c < C; c++){
            grid[r][c] += adjust[r][c];
            if(grid[r][c] < 0) grid[r][c] = 0;
        }
    }
}

void heater_work(){
    vector<vector<int>> add(R, vector<int>(C, 0));

    for(auto &h : heaters){
        vector<vector<bool>> worked(R, vector<bool>(C, false));

        int sr = h.hr + dr[h.hdir];
        int sc = h.hc + dc[h.hdir];
        int dir = h.hdir;
        if(sr < 0 || sc < 0 || sr >= R || sc >= C) continue;

        queue<tuple<int ,int ,int>> q;
        q.push({sr, sc, 5});
        worked[sr][sc] = true;
        add[sr][sc] += 5;

        while(!q.empty()){
            tuple<int ,int ,int> cur = q.front(); q.pop();

            int cur_r = get<0>(cur);
            int cur_c = get<1>(cur);
            int cur_p = get<2>(cur);

            if(cur_p == 1) continue;

            // #1.좌대각, #2.직진, #3.우대각 처리
            // #1 - 좌대각
            int ldir = Ld[dir];
            int nr = cur_r + dr[dir] + dr[ldir];
            int nc = cur_c + dc[dir] + dc[ldir];

            int check_wr = cur_r + dr[ldir];
            int check_wc = cur_c + dc[ldir];

            if(check_range(nr, nc) && check_range(check_wr, check_wc)){
                if(!worked[nr][nc]){
                    if(!(walls[cur_r][cur_c][ldir] || walls[check_wr][check_wc][dir])){
                        worked[nr][nc] = true;
                        add[nr][nc] += (cur_p - 1);
                        q.push({nr, nc, cur_p - 1});
                    }
                }
            }

            // #2 - 직진
            nr = cur_r + dr[dir];
            nc = cur_c + dc[dir];

            if(check_range(nr, nc)){
                if(!worked[nr][nc]){
                    if(!walls[cur_r][cur_c][dir]){
                        worked[nr][nc] = true;
                        add[nr][nc] += (cur_p - 1);
                        q.push({nr, nc, cur_p - 1});
                    }
                }
            }

            // #3 - 우대각
            int rdir = Rd[dir];
            nr = cur_r + dr[dir] + dr[rdir];
            nc = cur_c + dc[dir] + dc[rdir];

            check_wr = cur_r + dr[rdir];
            check_wc = cur_c + dc[rdir];

            if(check_range(nr, nc) && check_range(check_wr, check_wc)){
                if(!worked[nr][nc]){
                    if(!(walls[cur_r][cur_c][rdir] || walls[check_wr][check_wc][dir])){
                        worked[nr][nc] = true;
                        add[nr][nc] += (cur_p - 1);
                        q.push({nr, nc, cur_p - 1});
                    }
                }
            }
        }
    }
    for(int r=0; r < R; r++){
        for(int c=0; c < C; c++){
            grid[r][c] += add[r][c];
        }
    }
}

void input(){
    cin >> R >> C >> K;
    grid.resize(R, vector<int>(C, 0));
    walls.resize(R, vector<vector<bool>>(C, vector<bool>(5, false)));

    for(int i=0; i < R; i++){
        for(int j=0; j < C; j++){
            int r;
            cin >> r;
            if(r == 0) continue;
            
            if(r == 5){
                targets.push_back({i, j});
            }
            else{
                heaters.push_back({i, j, r});
            }
        }
    }

    cin >> W;
    for(int i=0; i < W; i++){
        int wr, wc, wdir;
        cin >> wr >> wc >> wdir;
        wr--; wc--;

        // 1
        if(wdir){
            walls[wr][wc][1] = true;
            walls[wr][wc+1][2] = true;
        }
        // 0
        else{
            walls[wr][wc][3] = true;
            walls[wr-1][wc][4] = true;
        }
    }
}

void func(){
    int result = 0;

    while(!check_k_value()){
        heater_work();
        adjust_temp();
        padding_down();
        result++;
        if(result > 100){
            result = 101;
            break;
        }
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
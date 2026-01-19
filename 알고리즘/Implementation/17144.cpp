#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int R, C, T;
int up_air = -1, down_air = -1;
vector<vector<int>> grid;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void spread(){
    vector<vector<int>> tmp(R, vector<int>(C, 0));
    tmp[up_air][0] = -1;
    tmp[down_air][0] = -1;

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            if(grid[y][x] <= 0) continue;

            int dust = grid[y][x];
            int spread_dust = dust / 5;
            int cnt = 0;

            if(spread_dust == 0){
                tmp[y][x] += dust;
                continue;
            }

            for(int d=0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
                if(grid[ny][nx] == -1)continue;
                tmp[ny][nx] += spread_dust;
                cnt++;
            }
            tmp[y][x] += dust - spread_dust * cnt;
        }
    }
    grid.swap(tmp);
}

void purify(){
    // 위쪽 공기 정화(반시계)
    int r = up_air;

    for(int y=r-1; y > 0; y--){
        grid[y][0] = grid[y-1][0];
    }
    for(int x=0; x < C-1; x++){
        grid[0][x] = grid[0][x+1];
    }
    for(int y=0; y < r; y++){
        grid[y][C-1] = grid[y+1][C-1];
    }
    for(int x=C-1; x > 1; x--){
        grid[r][x] = grid[r][x-1];
    }
    grid[r][1] = 0;

    // 아래쪽 공기 정화(시계)
    r = down_air;

    for(int y=r+1; y < R-1; y++){
        grid[y][0] = grid[y+1][0];
    }
    for(int x=0; x < C-1; x++){
        grid[R-1][x] = grid[R-1][x+1];
    }
    for(int y=R-1; y > r; y--){
        grid[y][C-1] = grid[y-1][C-1];
    }
    for(int x=C-1; x > 1; x--){
        grid[r][x] = grid[r][x-1];
    }
    grid[r][1] = 0;
}

void input(){
    cin >> R >> C >> T;
    grid.resize(R, vector<int>(C));

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            cin >> grid[y][x];
            if(grid[y][x] == -1){
                if(up_air == -1){
                    up_air = y;
                }
                else{
                    down_air = y;
                }
            }
        }
    }
}

void func(){
    int result = 0;
    
    while(T--){
        spread();
        purify();
    }

    for(int y=0; y < R; y++){
        for(int x=0; x < C; x++){
            if(grid[y][x] > 0){
                result += grid[y][x];
            }
            //cout << grid[y][x] << " ";
        }
        //cout << endl;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
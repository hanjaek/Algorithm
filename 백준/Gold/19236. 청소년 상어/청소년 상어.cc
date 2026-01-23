#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

struct Fish
{
    int x, y, dir;
    bool alive;
};

pair<int ,int> grid[4][4];
Fish fish[17];
int result = 0;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void move_fish(pair<int, int> grid[4][4], Fish fish[17], int sx, int sy){
    for(int num=1; num <= 16; num++){
        if(!fish[num].alive) continue;

        int cx = fish[num].x;
        int cy = fish[num].y;
        int cd = fish[num].dir;

        for(int d=0; d < 8; d++){
            int nd = (cd + d) % 8;
            int nx = cx + dx[nd];
            int ny = cy + dy[nd];

            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
            if(nx == sx && ny == sy) continue;

            int target_fish = grid[ny][nx].first;
            int target_dir = grid[ny][nx].second;

            grid[ny][nx] = {num, nd};
            grid[cy][cx] = {target_fish, target_dir};

            fish[num].x = nx; fish[num].y = ny; fish[num].dir = nd;

            if(target_fish != 0){
                fish[target_fish].x = cx;
                fish[target_fish].y = cy;
                fish[target_fish].dir = target_dir;
            }
            break;
        }
    }
}

void dfs(pair<int, int> grid[4][4], Fish fish[17], int sx, int sy, int sdir, int sum){
    result = max(result, sum);

    move_fish(grid, fish, sx, sy);

    for(int step=1; step < 4; step++){
        int nx = sx + dx[sdir] * step;
        int ny = sy + dy[sdir] * step;

        // 어차피 낮은 스텝순으로 증가하기 때문에 하나가 걸리면 나머지 스텝도 범위 내 불가능
        if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;

        int fish_num = grid[ny][nx].first;
        int fish_dir = grid[ny][nx].second;

        if(fish_num == 0) continue;

        pair<int, int> t_grid[4][4];
        Fish t_fish[17];

        for(int y=0; y < 4; y++){
            for(int x=0; x < 4; x++){
                t_grid[y][x] = grid[y][x];
            }
        }
        for(int i=1; i <= 16; i++){
            t_fish[i] = fish[i];
        }

        t_grid[ny][nx] = {0, 0};
        t_fish[fish_num].alive = false;
        
        dfs(t_grid, t_fish, nx, ny, fish_dir, sum + fish_num);
    }
}

void input(){
    for(int y=0; y < 4; y++){
        for(int x=0; x < 4; x++){
            int a, b;
            cin >> a >> b;
            b--;

            grid[y][x] = {a, b};
            fish[a] = {x, y, b, true};
        }
    }
}

void func(){
    int sx=0, sy=0;

    int start = grid[sy][sx].first;
    int sdir = grid[sy][sx].second;
    
    grid[sy][sx] = {0, 0};
    fish[start].alive = false;


    dfs(grid, fish, sx, sy, sdir, start);

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
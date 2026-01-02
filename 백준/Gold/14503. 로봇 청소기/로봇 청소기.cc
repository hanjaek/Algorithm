#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> grid;
int sx, sy, sd;

// 0:북, 1:동, 2:남, 3:서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void input(){
    cin >> N >> M;
    cin >> sy >> sx >> sd;

    grid.resize(N, vector<int>(M));
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
        }
    }
}

void func(){
    int result = 0;
    int cx = sx, cy = sy, cd = sd;

    while(true){
        bool check = false;

        if(grid[cy][cx] == 0){
            grid[cy][cx] = 2;
            result++;
        }

        for(int d=0; d < 4; d++){
            cd = (cd + 3) % 4;
            int nx = cx + dx[cd];
            int ny = cy + dy[cd];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(grid[ny][nx] == 0){
                cx = nx;
                cy = ny;
                check = true;
                break;
            }
        }
        if(check) continue;

        int back = (cd + 2) % 4;
        int bx = cx + dx[back];
        int by = cy + dy[back];

        if(bx < 0 || by < 0 || bx >= M || by >= N) break;
        if(grid[by][bx] == 1) break;

        cx = bx;
        cy = by;
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
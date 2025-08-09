#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid; // 0:빈 칸, 1: 벽, 2: 바이러스
int max_safe_area = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
        }
    }
}

int bfs(vector<vector<int>> board){
    queue<pair<int, int>> q;
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            if(board[y][x] == 2){
                q.push({x, y});
            }
        }
    }
    int safe_area = 0;

    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(board[ny][nx] == 0){
                board[ny][nx] = 2;
                q.push({nx, ny});
            }
        }
    }
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            if(board[y][x] == 0){
                safe_area++;
            }
        }
    }
    return safe_area;
}

void wall(int cnt, int start){
    if(cnt == 3){
        max_safe_area = max(max_safe_area, bfs(grid));
        return;
    }
    // 이건 중복 발생
    // for(int y=0; y < N; y++){
    //     for(int x=0; x < M; x++){
    //         if(grid[y][x] == 0){
    //             grid[y][x] = 1;
    //             wall(cnt+1);
    //             grid[y][x] = 0;
    //         }
    //     }
    // }
    for(int idx = start; idx < N*M; idx++){
        // 1차원 배열로 생각해서 2중 for문 없이 해결하는 방법(2중 for문도 가능 근데 코드 복잡)
        int y = idx / M;
        int x = idx % M;
        if(grid[y][x] == 0){
            grid[y][x] = 1;
            wall(cnt+1, idx+1);
            grid[y][x] = 0;
        }
    }
}

void func(){
    wall(0, 0);
    cout << max_safe_area;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}

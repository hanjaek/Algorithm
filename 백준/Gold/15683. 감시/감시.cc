#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<pair<int, int>> cctv;
int result = 1e9;

// 동:0, 남:1, 서:2, 북:3
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<vector<int>>> watch = {
    {}, 
    {{0}, {1}, {2}, {3}}, // 1번 cctv
    {{0, 2}, {1, 3}}, // 2
    {{0, 3}, {0, 1}, {1, 2}, {2, 3}}, // 3
    {{0, 2, 3}, {0, 1, 3}, {0, 1, 2}, {1, 2, 3}}, // 4
    {{0, 1, 2, 3}} // 5
};

int calc(vector<vector<int>> &grid){
    int cnt = 0;
    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            if(grid[y][x] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(int idx, vector<vector<int>> grid){
    if(idx == cctv.size()){
        result = min(result, calc(grid));
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int type = grid[y][x];

    for(vector<int> &dirs : watch[type]){
        vector<vector<int>> tgrid = grid;

        for(int dir : dirs){
            int nx = x, ny = y;
            
            while(true){
                nx += dx[dir];
                ny += dy[dir];
                if(nx < 0 || ny < 0 || nx >= M || ny >= N) break;
                if(tgrid[ny][nx] == 6) break;
                if(tgrid[ny][nx] == 0) tgrid[ny][nx] = -1;
            }
        }
        dfs(idx + 1, tgrid);
    }
}

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];

            if(1 <= grid[y][x] && grid[y][x] <= 5){
                cctv.push_back({x, y});
            }
        }
    }
}

void func(){
    dfs(0, grid);
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
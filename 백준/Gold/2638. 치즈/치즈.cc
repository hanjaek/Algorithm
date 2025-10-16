#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> air;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    air.resize(N, vector<bool>(M, false));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
        }
    }
}

bool bfs(){
    // 바깥 공기만 true로, 외곽은 모두 공기이기 때문에 0,0 스타트
    for(int y=0; y < N; y++){
        fill(air[y].begin(), air[y].end(), false);
    }
    queue<pair<int ,int>> q;
    q.push({0, 0});
    air[0][0] = true;

    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(air[ny][nx]) continue;
            if(grid[ny][nx]==0){
                air[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }

    // 이제 바깥공기 모두 체크완료, 녹일 치즈 구하기 (2면 이상 접촉)

    vector<pair<int, int>> melt;
    for(int y=1; y < N-1; y++){
        for(int x=1; x < M-1; x++){
            if(grid[y][x] == 1){
                int air_cnt = 0;
                
                for(int dir=0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(air[ny][nx]) air_cnt++;
                }
                if(air_cnt >= 2){
                    melt.push_back({x, y});
                }
            }
        }
    }

    // 더 이상 녹일 치즈 없으면 스톱 
    if(melt.empty()){
        return false;
    }

    for(auto[cx, cy] : melt){
        grid[cy][cx] = 0;
    }
    return true;
}

void func(){
    int hours = 0;
    while(bfs()) hours++;

    cout << hours << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
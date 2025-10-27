#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<string> grid;
int coins[2][2];
bool visited[20][20][20][20];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct State{
    int x1, y1;
    int x2, y2;
    int cnt;
};

void input(){
    cin >> N >> M;
    grid.resize(N);
    int idx = 0;

    for(int y=0; y < N; y++){
        cin >> grid[y];
        for(int x=0; x < M; x++){
            if(grid[y][x] == 'o'){
                coins[idx][0] = x;
                coins[idx][1] = y;
                idx++;
            }
        }
    }
}

int bfs(int x1, int y1, int x2, int y2){
    queue<State> q;
    q.push({x1, y1, x2, y2, 0});
    visited[y1][x1][y2][x2] = true;

    while(!q.empty()){
        State cur = q.front(); q.pop();
        if(cur.cnt >= 10){
            continue;
        }

        for(int d=0; d < 4; d++){
            int nx1 = cur.x1 + dx[d];
            int ny1 = cur.y1 + dy[d];
            int nx2 = cur.x2 + dx[d];
            int ny2 = cur.y2 + dy[d];

            bool out1 = (nx1 < 0 || ny1 < 0 || nx1 >= M || ny1 >= N);
            bool out2 = (nx2 < 0 || ny2 < 0 || nx2 >= M || ny2 >= N);

            if(out1 && out2){
                continue;
            }
            if(out1 || out2){
                return (cur.cnt + 1);
            }

            if(grid[ny1][nx1] == '#'){
                nx1 = cur.x1;
                ny1 = cur.y1;
            }
            if(grid[ny2][nx2] == '#'){
                nx2 = cur.x2;
                ny2 = cur.y2;
            }

            if(!visited[ny1][nx1][ny2][nx2]){
                q.push({nx1, ny1, nx2, ny2, cur.cnt + 1});
                visited[ny1][nx1][ny2][nx2] = true;
            }
        }
    }
    return -1;
}

void func(){
    for(int a=0; a < N; a++){
        for(int b=0; b < M; b++){
            for(int c=0; c < N; c++){
                for(int d=0; d < M; d++){
                    visited[a][b][c][d] = false;
                }
            }
        }
    }
    int x1 = coins[0][0];
    int y1 = coins[0][1];
    int x2 = coins[1][0];
    int y2 = coins[1][1];

    int result = bfs(x1, y1, x2, y2);

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
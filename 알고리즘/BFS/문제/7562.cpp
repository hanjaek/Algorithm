#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void input(){
    cin >> T;
}

int bfs(int L, int sx, int sy, int tx, int ty){
    if (sx == tx && sy == ty) return 0;

    vector<vector<int>> dist(L, vector<int>(L, -1));
    queue<pair<int, int>> q;

    dist[sy][sx] = 0;
    q.push({sx, sy});

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        for(int dir=0; dir < 8; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= L || ny >= L) continue;
            if(dist[ny][nx] == -1){
                dist[ny][nx] = dist[cy][cx] + 1;
                if(nx == tx && ny == ty) return dist[ny][nx];
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

void func(){
    while(T--){
        int L, sx, sy, tx, ty;
        cin >> L;
        cin >> sx >> sy;
        cin >> tx >> ty;
        cout << bfs(L, sx, sy, tx, ty) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
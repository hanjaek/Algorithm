#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int r1, c1, r2, c2;
vector<vector<int>> dist;

int dr[6] = {-2, -2, 0, 0, 2, 2};
int dc[6] = {-1, 1, -2, 2, -1, 1};

void input(){
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;
    dist.resize(N, vector<int>(N, -1));
}

void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r, c});
    dist[r][c] = 0;

    while(!q.empty()){
        auto [cr, cc] = q.front();
        q.pop();
        if(cr == r2 && cc == c2){
            return;
        }

        for(int dir=0; dir < 6; dir++){
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];
            if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if(dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[cr][cc] + 1;
            q.push({nr, nc});
        }
    }
}

void func(){
    bfs(r1, c1);
    cout << dist[r2][c2] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
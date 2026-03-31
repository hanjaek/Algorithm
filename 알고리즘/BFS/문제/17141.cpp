#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define endl "\n"

int N, M;
vector<vector<int>> grid;
vector<pair<int, int>> virus_idx;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<int> &perm){
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    int result = 0;

    for(int i=0; i < virus_idx.size(); i++){
        if(perm[i]){
            int x = virus_idx[i].first;
            int y = virus_idx[i].second;
            q.push({x, y});
            dist[x][y] = 0;
        }
    }

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(grid[nx][ny] == 1) continue;
            if(dist[nx][ny] != -1) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cx][cy] + 1;
        }
    }

    for(int x=0; x < N; x++){
        for(int y=0; y < N; y++){
            if(grid[x][y] != 1){
                if(dist[x][y] == -1) return 1e9;
                result = max(result, dist[x][y]);
            }
        }
    }
    return result;
}

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(N));

    for(int x=0; x < N; x++){
        for(int y=0; y < N; y++){
            cin >> grid[x][y];
            if(grid[x][y] == 2){
                virus_idx.push_back({x, y});
            }
        }
    }
}

void func(){
    int mn = 1e9;
    int v_size = virus_idx.size();

    vector<int> perm(v_size, 0);
    for(int i=v_size-M; i < v_size; i++){
        perm[i] = 1;
    }

    do{
        mn = min(mn, bfs(perm));
    }while(next_permutation(perm.begin(), perm.end()));
    
    if(mn == 1e9) cout << -1 << endl;
    else cout << mn << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
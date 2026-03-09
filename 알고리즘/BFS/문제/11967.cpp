#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"

int N, M;
vector<vector<bool>> grid;
vector<vector<vector<pair<int, int>>>> from_to;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool range_check(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

bool can_visit(int x, int y){
    for(int dir=0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!range_check(nx, ny)) continue;
        if(visited[nx][ny]) return true;
    }
    return false;
}

int bfs(int sx, int sy){
    queue<pair<int, int>> q;
    int cnt = 1;
    q.push({sx, sy});
    grid[sx][sy] = true;
    visited[sx][sy] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(pair<int, int> next : from_to[cx][cy]){
            int a = next.first;
            int b = next.second;

            if(grid[a][b]) continue;

            grid[a][b] = true;
            cnt++;

            if(can_visit(a, b) && !visited[a][b]){
                q.push({a, b});
                visited[a][b] = true;
            }
        }

        for(int dir=0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(!range_check(nx, ny)) continue;
            if(!grid[nx][ny]) continue;
            if(visited[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return cnt;
}

void input(){
    cin >> N >> M;
    grid.resize(N, vector<bool>(N, false));
    from_to.resize(N, vector<vector<pair<int, int>>>(N));
    visited.resize(N, vector<bool>(N, false));

    int x, y, a, b;
    for(int i=0; i < M; i++){
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;

        from_to[x][y].push_back({a, b});
    } 
}

void func(){
    int result = bfs(0, 0);
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
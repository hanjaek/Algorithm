#include <iostream>
#include <queue>

using namespace std;

char map[601][601];
bool visited[601][601];
int N, M;
int result = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(int &x, int&y){
    cin >> N >> M;
    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'I'){
                x = i;
                y = j;
            }
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(map[cx][cy] == 'P') result++;

        for(int i=0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny] || map[nx][ny] == 'X') continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void func(){
    if(result == 0){
        cout << "TT";
    }
    else{
        cout << result;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int startX=0, startY=0;
    input(startX, startY);
    bfs(startX, startY);
    func();
}
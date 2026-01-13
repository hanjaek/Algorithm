#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int N, K, L;
vector<vector<int>> grid;
queue<pair<int, char>> turn;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input(){
    cin >> N >> K;
    grid.assign(N, vector<int>(N, 0));

    for(int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        grid[x][y] = 1;
    }

    cin >> L;
    for(int i = 0; i < L; i++){
        int t;
        char d;
        cin >> t >> d;
        turn.push({t, d});
    }
}

void func(){
    deque<pair<int,int>> snake;
    snake.push_back({0, 0});
    grid[0][0] = 2;

    int dir = 0;
    int time = 0;

    while(true){
        time++;

        int hy = snake.front().first;
        int hx = snake.front().second;

        int ny = hy + dy[dir];
        int nx = hx + dx[dir];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
        if(grid[ny][nx] == 2) break;

        snake.push_front({ny, nx});

        if(grid[ny][nx] == 1){
            grid[ny][nx] = 2;
        } else {
            grid[ny][nx] = 2;
            auto tail = snake.back();
            snake.pop_back();
            grid[tail.first][tail.second] = 0;
        }

        if(!turn.empty() && turn.front().first == time){
            char td = turn.front().second;
            turn.pop();
            if(td == 'D') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
        }
    }

    cout << time << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    func();
}
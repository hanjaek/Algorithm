#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int dice[6] = {0, 0, 0, 0, 0, 0};
int sx, sy;
vector<vector<int>> grid;

//동:1, 서:2, 북:3, 남:4
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 모든 테스트 케이스는 통과 하지만, 실패
// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

void input(){
    cin >> N >> M >> sx >> sy >> K;
    grid.resize(N, vector<int>(M));

    for(int y=0; y < N; y++){
        for(int x=0; x < M; x++){
            cin >> grid[y][x];
        }
    }
}

void func(){
    int cx = sy, cy = sx;

    for(int i=0; i < K; i++){
        int move;
        cin >> move;
        int dir = move - 1;

        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

        // 주사위 굴리기
        // 동
        if(move == 1){
            swap(dice[3], dice[5]);
            swap(dice[0], dice[5]);
            swap(dice[2], dice[5]);
        }
        // 서
        else if(move == 2){
            swap(dice[3], dice[5]);
            swap(dice[2], dice[3]);
            swap(dice[0], dice[3]);
        }
        // 북
        else if(move == 3){
            swap(dice[1], dice[5]);
            swap(dice[4], dice[5]);
            swap(dice[0], dice[4]);
        }
        // 남
        else{
            swap(dice[1], dice[5]);
            swap(dice[0], dice[1]);
            swap(dice[0], dice[4]);
        }

        // 이동한 칸 바닥이 0일 때
        if(grid[ny][nx] == 0){
            grid[ny][nx] = dice[5];
        }
        // 0이 아닐 때
        else{
            dice[5] = grid[ny][nx];
            grid[ny][nx] = 0;
        }
        cx = nx; cy = ny;

        cout << dice[0] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
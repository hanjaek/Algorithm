#include <iostream>
#include <vector>
using namespace std;

// =========================================
const int N = 5;       // 그리드 크기
const int JUMP = 3;    // 점프 단위
// =========================================

int main() {
    // 1) 달팽이 경로 미리 만들기 ((1,1) → 중앙까지 순서대로)
    vector<pair<int,int>> path;
    vector<vector<bool>> visited(N+2, vector<bool>(N+2, false));
    int dx[4] = {0, 1, 0, -1};   // 우, 하, 좌, 상
    int dy[4] = {1, 0, -1, 0};
    int x = 1, y = 1, dir = 0;

    for (int i = 0; i < N*N; i++) {
        path.push_back({x, y});
        visited[x][y] = true;
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 1 || ny < 1 || nx > N || ny > N || visited[nx][ny]) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx; y = ny;
    }

    // 2) 경로 따라 점프하며 1~N*N 채우기
    vector<vector<int>> board(N+2, vector<int>(N+2, 0));
    int placed = 0, pathIdx = 0;
    int lastX = 0, lastY = 0;

    // (1,1)에 1 배치
    board[path[0].first][path[0].second] = ++placed;
    lastX = path[0].first;
    lastY = path[0].second;
    pathIdx = 1;

    while (placed < N*N) {
        int counted = 0;
        int placeX = -1, placeY = -1;
        int safety = 0;

        while (counted < JUMP) {
            if (++safety > N*N*100) break;          // 무한루프 방지
            if (pathIdx >= (int)path.size()) {
                pathIdx = 0;                         // 중앙 도달 → (1,1)부터 다시
            }
            int cx = path[pathIdx].first;
            int cy = path[pathIdx].second;
            pathIdx++;
            if (board[cx][cy] == 0) {                // 빈 칸만 카운트
                counted++;
                if (counted == JUMP) {
                    placeX = cx;
                    placeY = cy;
                }
            }
            // 채워진 칸은 통과(점프)
        }
        board[placeX][placeY] = ++placed;
        lastX = placeX;
        lastY = placeY;
    }

    // 3) 출력
    cout << "N = " << N << ", JUMP = " << JUMP << "\n";
    cout << "N*N(" << N*N << ")번째 숫자의 좌표: ("
         << lastX << ", " << lastY << ")\n\n";

    cout << "최종 보드:\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
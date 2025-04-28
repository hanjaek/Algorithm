#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int box[101][101][101];
int M, N, H;
queue <pair<pair<int, int>, int>> q;
int dm[6] = { -1,1,0,0,0,0 };
int dn[6] = { 0,0,-1,1,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };

void bfs() {
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int m = q.front().first.first;
            int n = q.front().first.second;
            int h = q.front().second;
            q.pop();
            for (int j = 0; j < 6; j++) {
                int new_m = m + dm[j];
                int new_n = n + dn[j];
                int new_h = h + dh[j];
                if ((new_m >= 0 && new_m < H) && (new_n >= 0 && new_n < N)
                    && (new_h >= 0 && new_h < M) && box[new_m][new_n][new_h] == 0) {
                    q.push(make_pair(make_pair(new_m, new_n), new_h));
                    box[new_m][new_n][new_h] = 1;
                }
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    cout << "-1";
                    exit(0);
                }
            }
        }
    }
    cout << cnt - 1;

}
int main() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    q.push(make_pair(make_pair(i, j), k));
                }
            }
        }
    }
    bfs();
}
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &matrix, int x, int y, int m, int n) {

    matrix[x][y] = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (matrix[nx][ny] == 1) {
                dfs(matrix, nx, ny, m, n);
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            matrix[x][y] = 1;
        }

        int cnt = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (matrix[x][y] == 1) {
                    dfs(matrix, x, y, m, n);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

}

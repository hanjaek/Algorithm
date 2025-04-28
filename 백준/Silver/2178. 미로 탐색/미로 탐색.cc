#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
bool visited[101][101];
int dist[101][101];
int N, M;

int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	dist[x][y] = 1;

	while (!q.empty()) {
		int x_ = q.front().first;
		int y_ = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x_ + dir_x[i];
			int new_y = y_ + dir_y[i];

			if((0<=new_x && new_x<N)&&(0<=new_y&&new_y<M)
				&& (!visited[new_x][new_y]) && (map[new_x][new_y] == 1)) {
				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = true;
				dist[new_x][new_y] = dist[x_][y_] + 1;
			}
		}

	}
	return dist[N - 1][M - 1];

}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	cout << bfs(0, 0);
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int map[26][26];
bool visited[26][26];
int cnt;
int house = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector <int > v;
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	cnt = 0;
	cnt++;

	while (!q.empty()) {
		int x_ = q.front().first;
		int y_ = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int new_x = x_ + dx[i];
			int new_y = y_ + dy[i];

			if ((new_x >= 0 && new_x < N) && (new_y >= 0 && new_y < N)
				&& (!visited[new_x][new_y]) && (map[new_x][new_y] == 1)) {
				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = true;
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((!visited[i][j]) && (map[i][j] == 1)) {
				bfs(i, j);
				house++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << house << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
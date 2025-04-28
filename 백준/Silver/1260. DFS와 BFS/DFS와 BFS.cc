#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited_dfs[1001];
bool visited_bfs[1001];
vector<int> v[1001];

void dfs(int x) {

	visited_dfs[x] = true;
	cout << x << " ";
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!visited_dfs[y]) {
			dfs(y);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited_bfs[x] = true;
	
	while (!q.empty()) {
		int y = q.front();
		cout << y << " ";
		q.pop();
		for (int i = 0; i < v[y].size(); i++) {
			int z = v[y][i];
			if (!visited_bfs[z]) {
				q.push(z);
				visited_bfs[z] = true;
			}
		}
	}
}

int main() {

	int N, M, V, v1, v2;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	for (int i = 0; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(V);
	cout << endl;
	bfs(V);
}
#include <iostream>
#include <vector>

using namespace std;
int node, edge, e1, e2;
vector<int> v[101];
bool visited[101];
int cnt = 0;

int dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!visited[y]) {
			dfs(y);
			cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> e1 >> e2;
		v[e1].push_back(e2);
		v[e2].push_back(e1);
	}
	cout << dfs(1);

}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N, M, X;
vector<vector<int>> costs;
vector<vector<int>> rev_costs;

vector<int> dijkstra(int start, vector<vector<int>> v){
    vector<int> dist(N+1, 1e9);
    vector<bool> visited(N+1, false);

    dist[start] = 0;

    for(int i=1; i <= N; i++){
        int cur = 0;
        int mn = 1e9;

        for(int j=1; j <= N; j++){
            if(!visited[j] && dist[j] < mn){
                cur = j;
                mn = dist[j];
            }
        }
        if(!cur) break;
        visited[cur] = true;

        for(int next=1; next <= N; next++){
            if(!v[cur][next]) continue;

            if(dist[next] > dist[cur] + v[cur][next]){
                dist[next] = dist[cur] + v[cur][next];
            }
        }
    }
    return dist;
}

void input(){
    cin >> N >> M >> X;
    costs.resize(N+1, vector<int>(N+1, 0));
    rev_costs.resize(N+1, vector<int>(N+1, 0));

    int from, to, c;
    for(int i=0; i < M; i++){
        cin >> from >> to >> c;

        costs[from][to] = c;
        rev_costs[to][from] = c;
    }
}

void func(){
    vector<int> i_to_X = dijkstra(X, rev_costs);
    vector<int> X_to_i = dijkstra(X, costs);
    int result = -1;

    for(int i=1; i <= N; i++){
        if(i_to_X[i] == 1e9 || X_to_i[i] == 1e9) continue;
        result = max(result, i_to_X[i] + X_to_i[i]);
    }

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
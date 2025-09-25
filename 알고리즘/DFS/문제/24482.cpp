#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> E;
vector<int> dist;

void input(){
    cin >> N >> M >> R;
    E.resize(N+1);
    dist.resize(N+1, -1);

    for(int i=0; i < M; i++){
        int u, v;
        cin >> u >> v;

        E[u].push_back(v);
        E[v].push_back(u);
    }
    for(int i=1; i <= N; i++){
        sort(E[i].begin(), E[i].end(), greater<>());
    }
}

void dfs(int node, int depth){
    dist[node] = depth;

    for(int next : E[node]){
        if(dist[next] == -1){
            dfs(next, depth + 1);
        }
    }
}

void func(){
    dfs(R, 0);
    for(int i=1; i <= N; i++){
        cout << dist[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
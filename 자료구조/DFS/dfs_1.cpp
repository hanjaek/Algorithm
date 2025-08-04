#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, start;
vector<vector<int>> graph;
vector<bool> visited;

void input(){
    cin >> N >> M >> start;
    graph.resize(N+1);
    visited.resize(N+1, false);

    for(int i=0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int node){
    visited[node] = true;
    cout << node << " ";

    for(int next : graph[node]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

void func(){
    for(int i=1; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
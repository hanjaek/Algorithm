#include <iostream>
#include <vector>
#include <queue>

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

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int next : graph[cur]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void func(){
    bfs(start);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
int result;

void input(){
    cin >> N >> M;
    adj.resize(N+1);
    visited.resize(N+1, false);

    for(int i = 0; i < N-1; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

bool dfs(int node, int target, int dist){
    visited[node] = true;
    if(node == target){
        result = dist;
        return true;
    }

    for(auto [next, w] : adj[node]){
        if(!visited[next]){
            if(dfs(next, target, dist + w)){
                return true;
            }
        }
    }
    return false;
}

void func(){
    while(M--){
        visited.assign(N+1, false);
        result = 0;
        int u, v;
        cin >> u >> v;

        dfs(u, v, 0);
        cout << result << "\n";

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
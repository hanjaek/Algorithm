#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<pair<int ,int>>> E;
vector<bool> visited;
int far_node;
int max_dist = 0;

void input(){
    cin >> N;
    E.resize(N+1);
    visited.resize(N+1, false);

    for(int i=0; i < N-1; i++){
        int u, v, w;
        cin >> u >> v >> w;

        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
}

void dfs(int node, int dist){
    visited[node] = true;
    if(dist > max_dist){
        max_dist = dist;
        far_node = node;
    }

    for(auto [next, w] : E[node]){
        if(!visited[next]){
            dfs(next, dist + w);
        }
    }
}

void func(){
    dfs(1, 0);

    visited.assign(N+1, false);
    max_dist = 0;
    dfs(far_node, 0);

    cout << max_dist << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
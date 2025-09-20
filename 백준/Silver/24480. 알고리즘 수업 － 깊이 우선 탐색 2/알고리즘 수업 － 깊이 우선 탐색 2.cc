#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> E;
vector<int> visited;
int seq = 1;

void input(){
    cin >> N >> M >> R;

    E.resize(N+1);
    visited.resize(N+1, 0);

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

void dfs(int node){
    visited[node] = seq++;
    for(int next : E[node]){
        if(visited[next] == 0){
            dfs(next);
        }
    }
}

void func(){
    dfs(R);
    for(int i=1; i <= N; i++){
        cout << visited[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
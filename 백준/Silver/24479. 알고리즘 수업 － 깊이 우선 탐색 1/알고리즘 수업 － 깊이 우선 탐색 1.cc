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
        sort(E[i].begin(), E[i].end());
    }
}

void dfs(int V, vector<vector<int>>& E, int R){
    visited[R] = seq++;
    for(int next : E[R]){
        if(visited[next] == 0){
            dfs(V, E, next);
        }
    }
}

void func(){
    dfs(N, E, R);
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
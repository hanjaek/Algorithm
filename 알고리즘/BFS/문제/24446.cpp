#include <iostream>
#include <vector>
#include <queue>
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
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : E[cur]){
            if(dist[next] == -1){
                q.push(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
}

void func(){
    bfs(R);
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
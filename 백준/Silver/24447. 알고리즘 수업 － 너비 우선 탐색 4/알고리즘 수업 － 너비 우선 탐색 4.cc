#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> E;
vector<int> dist;
vector<int> seq_v;
int seq = 1;

void input(){
    cin >> N >> M >> R;
    E.resize(N+1);
    dist.resize(N+1, -1);
    seq_v.resize(N+1, 0);

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

void bfs(int node){
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    seq_v[node] = seq++;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : E[cur]){
            if(dist[next] == -1){
                q.push(next);
                dist[next] = dist[cur] + 1;
                seq_v[next] = seq++;
            }
        }
    }
}

void func(){
    long long result = 0;
    bfs(R);

    for(int i=1; i <= N; i++){
        result += (long long)dist[i] * seq_v[i];
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
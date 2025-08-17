#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> adj;
vector<int> parent;

void input(){
    cin >> N;
    adj.resize(N+1);
    parent.resize(N+1, 0);

    for(int i=0; i < N - 1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}

void bfs(){
    queue<int> q;
    q.push(1);
    parent[1] = -1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int next : adj[cur]){
            if(parent[next] == 0){
                parent[next] = cur;
                q.push(next);
            }
        }
    }
}

void func(){
    bfs();

    for(int i=2; i <= N; i++){
        cout << parent[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
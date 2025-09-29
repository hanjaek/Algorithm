#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> E;
vector<int> dist;

void input(){
    cin >> n >> m;
    E.resize(n+1);
    dist.resize(n+1, -1);

    for(int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;

        E[a].push_back(b);
        E[b].push_back(a);
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
            if(dist[next] != -1) continue;
            q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }
}

void func(){
    int cnt = 0;
    bfs(1);

    for(int i=2; i <= n; i++){
        if(dist[i] == 1 || dist[i] == 2){
            cnt++;
        }
    }

    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
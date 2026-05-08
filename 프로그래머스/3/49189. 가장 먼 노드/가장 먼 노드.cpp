#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> dist;

void init_adj(vector<vector<int>> &adj, vector<vector<int>> &edge){
    for(auto e : edge){
            int v1 = e[0];
            int v2 = e[1];

            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : adj[cur]){
            if(dist[next] != -1) continue;
            
            q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    adj.resize(n+1);
    dist.resize(n+1, -1);
    
    init_adj(adj, edge);
    bfs(1);
    
    int mx_dist = *max_element(dist.begin(), dist.end());
    
    for(int i=1; i <= n; i++){
        if(dist[i] == mx_dist) answer++;
    }
    
    return answer;
}
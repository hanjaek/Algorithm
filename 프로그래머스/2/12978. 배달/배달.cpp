#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void init_adj(vector<vector<int>> &road){
    for(auto r : road){
        int from = r[0];
        int to = r[1];
        int cost = r[2];
        
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }
}   

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cur_dist > dist[cur]) continue;
        
        for(pair<int, int> next : adj[cur]){
            int next_node = next.first;
            int cost = next.second;
            
            if(dist[next_node] > dist[cur] + cost){
                dist[next_node] = dist[cur] + cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    adj.resize(N+1);
    dist.resize(N+1, 1e9);
    
    init_adj(road);
    dijkstra(1);
    
    for(int i=1; i <= N; i++){
        if(dist[i] <= K) answer++;
    }

    return answer;
}
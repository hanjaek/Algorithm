#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"

int N, M;
vector<vector<pair<int, int>>> E;
vector<int> dist;

void input(){
    cin >> N >> M;
    E.resize(N+1);
    dist.resize(N+1, 1e9);

    for(int i=0; i < M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;

        E[from].push_back({cost, to});
        E[to].push_back({cost, from});
    }
}

void func(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if(cur_cost > dist[cur]) continue;

        for(pair<int ,int> next : E[cur]){
            int next_node = next.second;
            int next_cost = next.first;

            if(dist[next_node] > dist[cur] + next_cost){
                dist[next_node] = dist[cur] + next_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    cout << dist[N] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
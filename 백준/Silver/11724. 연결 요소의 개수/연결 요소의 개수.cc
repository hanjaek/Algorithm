#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

int N, M;
vector<int> edges[MAX];
bool visited[MAX];

void input(){
    cin >> N >> M;

    for(int i=0; i < M; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}

void dfs(int node){
    visited[node] = true;
    for(auto next : edges[node]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

void result(){
    int cnt = 0;
    for(int i=1; i <= N; i++){  // 1<= u,v <= N 
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    result();
}
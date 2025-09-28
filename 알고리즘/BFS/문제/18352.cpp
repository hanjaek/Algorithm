#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<vector<int>> E;
vector<int> dist;

void input(){
    cin >> N >> M >> K >> X;
    E.resize(N+1);
    dist.resize(N+1, -1);

    for(int i=0; i < M; i++){
        int A, B;
        cin >> A >> B;

        E[A].push_back(B);
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
    vector<int> result;
    bfs(X);

    for(int city=1; city <= N; city++){
        if(dist[city] == K) result.push_back(city);
    }

    if(result.empty()){
        cout << -1 << "\n";
        return;
    }

    sort(result.begin(), result.end());
    for(int city : result){
        cout << city << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> E;
vector<int> dist;

void input(){
    cin >> N >> M;
    E.resize(N+1);
    dist.resize(N+1, -1);

    for(int i=0; i < M; i++){
        int A, B;
        cin >> A >> B;

        E[A].push_back(B);
        E[B].push_back(A);
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
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

void func(){
    bfs(1);

    int max_dist = 0;
    int min_idx = 1;
    int cnt = 0;

    for(int i=1; i <= N; i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
            min_idx = i;
            cnt = 1;
        }
        else if(dist[i] == max_dist){
            if(i < min_idx){
                min_idx = i;
            }
            cnt++;
        }
    }
    cout << min_idx << " " << max_dist << " " << cnt << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
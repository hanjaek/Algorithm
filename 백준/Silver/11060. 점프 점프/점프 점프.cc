#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> maze;
vector<int> dist;

void input(){
    cin >> N;
    maze.resize(N);
    dist.resize(N, -1);

    for(int i=0; i < N; i++){
        cin >> maze[i];
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int jump = maze[cur];

        for(int next = cur + 1; next <= cur + jump && next < N; next++){
            if(dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
}

void func(){
    bfs(0);
    cout << dist[N-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
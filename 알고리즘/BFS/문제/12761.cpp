#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, sx, ex;
int dist[100001];

void input(){
    cin >> A >> B >> sx >> ex;
}

void bfs(){
    queue<int> q;
    fill(dist, dist + 100001, -1);

    dist[sx] = 0;
    q.push(sx);

    while(!q.empty()){
        int cx = q.front();
        q.pop();

        if(cx == ex) return;

        for(int nx : {cx-1, cx+1, cx - A, cx + A, cx - B, cx + B, cx * A, cx * B}){
            if(nx < 0 || nx > 100000) continue;
            if(dist[nx] == -1){
                dist[nx] = dist[cx] + 1;
                q.push(nx);
            }
        }
    }
}

void func(){
    bfs();
    cout << dist[ex] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
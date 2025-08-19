#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100001

int N, K;
int dist[MAX];
int cnt[MAX];

void input(){
    cin >> N >> K;
}

void bfs(int start, int target){
    fill(dist, dist + MAX, -1);
    fill(cnt, cnt + MAX, 0);

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    cnt[start] = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        if(dist[target] != -1 && dist[cur] > dist[target]) break;

        for(int next : {cur-1, cur+1, cur*2}){
            if(next < 0 || next >= MAX) continue;

            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                cnt[next] = cnt[cur];
                q.push(next);
            }
            else if(dist[next] == dist[cur] + 1){
                cnt[next] += cnt[cur];
            }
        }
    }
}

void func(){
    bfs(N, K);
    cout << dist[K] << "\n" << cnt[K];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
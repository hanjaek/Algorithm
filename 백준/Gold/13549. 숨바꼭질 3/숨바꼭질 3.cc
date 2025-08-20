#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

#define MAX 100001

int N, K;
int dist[MAX];

void input(){
    cin >> N >> K;
}

int bfs(int start, int target){
    fill(dist, dist + MAX, -1);
    deque<int> dq;
    dq.push_back(start);
    dist[start] = 0;

    while(!dq.empty()){
        int cur = dq.front(); dq.pop_front();
        if(cur == target) return dist[cur];

        int n_0 = cur * 2;
        if(n_0 >= 0 && n_0 < MAX && (dist[n_0] == -1 || dist[n_0] > dist[cur])){
            dist[n_0] = dist[cur];
            dq.push_front(n_0);
        }

        for(int n_1 : {cur-1, cur+1}){
            if(n_1 < 0 || n_1 >= MAX) continue;
            if(dist[n_1] == -1 || dist[n_1] > dist[cur] + 1){
                dist[n_1] = dist[cur] + 1;
                dq.push_back(n_1);
            }
        }
    }
    return -1;
}

void func(){
    int result = bfs(N, K);
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
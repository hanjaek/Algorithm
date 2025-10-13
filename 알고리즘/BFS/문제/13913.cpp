#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100001

int N, K;
int dist[MAX];
int previous[MAX];

void input(){
    cin >> N >> K;

    fill(dist, dist + MAX, -1);
    fill(previous, previous + MAX, -1);
}

int bfs(int start, int target){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    previous[start] = -1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == target){
            return dist[cur];
        }

        for(int next : {cur*2, cur+1, cur-1}){
            if(next < 0 || next >= MAX) continue;
            if(dist[next] == -1){
                q.push(next);
                dist[next] = dist[cur] + 1;
                previous[next] = cur;
            }
        }
    }
    return -1;
}

void func(){
    vector<int> seq;
    int min_time = bfs(N, K);

    for(int i=K; i != -1; i=previous[i]){
        seq.push_back(i);
    }
    reverse(seq.begin(), seq.end());
    
    cout << min_time << "\n";
    for(int i=0; i < seq.size(); i++){
        cout << seq[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
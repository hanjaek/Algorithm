#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> tp;
vector<int> cnt;

void input(){
    cin >> N >> M;
    tp.resize(101, 0);
    cnt.resize(101, -1);

    for(int i=0; i < N; i++){
        int x, y;
        cin >> x >> y;
        tp[x] = y;
    }
    for(int i=0; i < M; i++){
        int u, v;
        cin >> u >> v;
        tp[u] = v;
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    cnt[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int dice=1; dice <= 6; dice++){
            int next = cur + dice;
            if(next > 100) continue;
            if(tp[next] != 0) next = tp[next];

            if(cnt[next] == -1){
                cnt[next] = cnt[cur] + 1;
                q.push(next);
            }

            if(next == 100) return;
        }
    }
}

void func(){
    bfs(1);
    cout << cnt[100] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
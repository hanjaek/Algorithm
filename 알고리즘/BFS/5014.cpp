#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// F: 총 층수, S: 현재층, G:도착층
int F, S, G, U, D;
vector<int> dist;

void input(){
    cin >> F >> S >> G >> U >> D;
    dist.resize(F+1, -1);
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == G) return;

        for(int next : {cur + U, cur - D}){
            if(next > F || next < 1) continue;
            if(dist[next] == -1){
                q.push(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
}

void func(){
    bfs(S);

    if(dist[G] == -1){
        cout << "use the stairs" << "\n";
    }
    else{
        cout << dist[G] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
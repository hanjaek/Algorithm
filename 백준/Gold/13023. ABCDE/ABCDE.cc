#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> E;
vector<bool> visited;
bool flag = false;

void input(){
    cin >> N >> M;
    E.resize(N);
    visited.resize(N, false);

    for(int i=0; i < M; i++){
        int a, b;
        cin >> a >> b;

        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int node, int depth){
    if(flag) return;
    if(depth == 4){
        flag = true;
        return;
    }
    visited[node] = true;

    for(int next : E[node]){
        if(!visited[next]){
            dfs(next, depth+1);
            if(flag) return;
        }
    }
    visited[node] = false;
}

void func(){
    for(int i=0; i < N && !flag; i++){
        dfs(i, 0);
    }

    cout << (flag ? 1 : 0) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
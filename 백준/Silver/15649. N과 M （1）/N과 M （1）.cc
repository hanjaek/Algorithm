#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> selected;
vector<bool> used;

void input(){
    cin >> N >> M;
    selected.resize(M);
    used.resize(N+1, false);
}

void dfs(int depth){
    if(depth == M){
        for(int i=0; i < M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int num = 1; num <= N; num++){
        if(used[num]) continue;

        used[num] = true;
        selected[depth] = num;

        dfs(depth + 1);
        used[num] = false;
    }
}

void func(){
    dfs(0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
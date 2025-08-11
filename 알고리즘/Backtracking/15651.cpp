#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> selected;

void input(){
    cin >> N >> M;
    selected.resize(M);
}

void dfs(int depth){
    if(depth == M){
        for(int i=0; i < M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int num=1; num <= N; num++){
        selected[depth] = num;
        dfs(depth + 1);
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
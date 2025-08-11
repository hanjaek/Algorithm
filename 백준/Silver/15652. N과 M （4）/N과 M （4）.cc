#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> selected;

void input(){
    cin >> N >> M;
    selected.resize(M);
}

void dfs(int depth, int start){
    if(depth == M){
        for(int i=0; i < M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int num = start; num <= N; num++){
        selected[depth] = num;
        dfs(depth + 1, num);
    }
}

void func(){
    dfs(0, 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
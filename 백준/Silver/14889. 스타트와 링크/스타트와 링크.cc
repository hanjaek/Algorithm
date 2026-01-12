#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> grid;
vector<bool> selected;
int min_diff = 1e9;

void calc_diff(){
    int start_team = 0;
    int link_team = 0;

    for(int i=0; i < N; i++){
        for(int j=i+1; j < N; j++){
            if(selected[i] && selected[j]){
                start_team += (grid[i][j] + grid[j][i]);
            }
            else if(!selected[i] && !selected[j]){
                link_team += (grid[i][j] + grid[j][i]);
            }
        }
    }
    min_diff = min(min_diff, abs(start_team - link_team));
}

void dfs(int idx, int cnt){
    if(cnt == N/2){
        calc_diff();
        return;
    }
    
    for(int i=idx; i < N; i++){
        selected[i] = true;
        dfs(i+1, cnt+1);
        selected[i] = false;
    }
}

void input(){
    cin >> N;
    grid.resize(N, vector<int>(N));
    selected.resize(N, false);

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            cin >> grid[i][j];
        }
    }
}

void func(){
    // 대칭을 없애기 위해 1번 선수는 start팀 고정
    selected[0] = true;
    dfs(1, 1);
    cout << min_diff << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
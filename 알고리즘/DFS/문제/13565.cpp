#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int M, N;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> M >> N;
    grid.resize(M);
    visited.resize(M, vector<bool>(N, false));

    for(int y=0; y < M; y++){
        cin >> grid[y];
    }
}

bool dfs(){
    stack<pair<int, int>> st;

    for(int x=0; x < N; x++){
        if(grid[0][x] == '0'){
            st.push({x, 0});
            visited[0][x] = true;
        }
    }

    while(!st.empty()){
        auto [cx, cy] = st.top(); st.pop();
        if(cy == M-1) return true;

        for(int d=0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(grid[ny][nx] == '0' && !visited[ny][nx]){
                st.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
    return false;
}

void func(){
    cout << (dfs() ? "YES" : "NO") << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
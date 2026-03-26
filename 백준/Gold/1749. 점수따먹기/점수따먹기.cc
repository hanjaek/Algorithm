#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N, M;
vector<vector<int>> grid;

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(M, 0));

    for(int x=0; x < N; x++){
        for(int y=0; y < M; y++){
            cin >> grid[x][y];
        }
    }
}

void func(){
    int result = -1e9;

    for(int top = 0; top < N; top++){
        vector<int> col_sum(M, 0);

        for(int bottom = top; bottom < N; bottom++){
            for(int col = 0; col < M; col++){
                col_sum[col] += grid[bottom][col];
            }

            int cur = col_sum[0];
            int best = col_sum[0];

            for(int col = 1; col < M; col++){
                cur = max(col_sum[col], cur + col_sum[col]);
                best = max(best, cur);
            }
            result = max(result, best);
        }
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
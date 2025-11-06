#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<int>> sum;

void input(){
    cin >> N >> M;
    grid.resize(N+1, vector<int>(N+1));
    sum.resize(N+1, vector<int>(N+1, 0));

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            cin >> grid[y][x];
        }
    }
}

void func(){
    int result = 0;

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            sum[y][x] = sum[y-1][x] + sum[y][x-1] - sum[y-1][x-1] + grid[y][x];
        }
    }
    while(M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        result = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
        cout << result << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
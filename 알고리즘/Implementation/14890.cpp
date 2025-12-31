#include <iostream>
#include <vector>

using namespace std;

int N, L;
vector<vector<int>> grid;

void input(){
    cin >> N >> L;
    grid.resize(N, vector<int>(N));

    for(int y=0; y < N; y++){
        for(int x=0; x < N; x++){
            cin >> grid[y][x];
        }
    }
}

bool check_line(vector<int> &line){
    vector<bool> used(N, false);

    for(int i=0; i < N-1; i++){
        int diff = line[i+1] - line[i];

        if(diff == 0) continue;
        // 오르막
        if(diff == 1){
            for(int k=i; k >= i-L+1; k--){
                if(k < 0) return false;
                if(used[k]) return false;
                if(line[k] != line[i]) return false;
                used[k] = true;
            }
            // for(int k=i; k >= i-L+1; k--){
            //     cout << used[k] << "\n";
            // }
        }
        // 내리막
        else if(diff == -1){
            for(int k=i+1; k <= i+L; k++){
                if(k >= N) return false;
                if(used[k]) return false;
                if(line[k] != line[i+1]) return false;
                used[k] = true;
            }
            i += L - 1; // for에서 ++되니까 -1 해줌.
        }
        // 높이 차이 2이상(불가)
        else{
            return false;
        }
    }
    return true;
}

void func(){
    int result = 0;

    // 행부터 검사
    for(int y=0; y < N; y++){
        vector<int> line(N);
        for(int x=0; x < N; x++){
            line[x] = grid[y][x];
        }
        if(check_line(line)) result++;
    }

    // 열 검사
    for(int x=0; x < N; x++){
        vector<int> line(N);
        for(int y=0; y < N; y++){
            line[y] = grid[y][x];
        }
        if(check_line(line)) result++;
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
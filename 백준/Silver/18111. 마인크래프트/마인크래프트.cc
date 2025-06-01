#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, B;
vector<vector<int>> land;
int max_height = 0, min_height = 256;
int result_time = 1e9;
int result_height = 0;

void input(){
    cin >> N >> M >> B;
    land.assign(N,vector<int>(M));

    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            cin >> land[i][j];
            min_height = min(min_height, land[i][j]);
            max_height = max(max_height, land[i][j]);
        }
    }
}

void func(){
    for(int h = min_height; h <= max_height; h++){
        int remove = 0, add = 0;

        for(int i=0; i < N; i++){
            for(int j=0; j < M; j++){
                int diff = land[i][j] - h;
                if(diff > 0){
                    remove += diff;
                }else if(diff < 0){
                    add -= diff;
                }
            }
        }
        if (remove + B >= add){
            int time = remove*2 + add;
            if(time < result_time || (time == result_time && h > result_height)){
                result_time = time;
                result_height = h;
            }
        }
    }

    cout << result_time << " " << result_height;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
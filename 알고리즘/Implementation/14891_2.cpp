#include <iostream>
#include <string>

using namespace std;

int N = 4;
int K;
int gear[4][8];
int top_idx[4] = {0, 0, 0, 0};

void input(){
    for(int i=0; i < N; i++){
        string s;
        cin >> s;
        for(int j=0; j < s.size(); j++){
            gear[i][j] = s[j] - '0';
        }
    }
    cin >> K;
}

// top_idx 기준 톱니 상태
int tooth(int idx, int pos){
    int cur_tooth = gear[idx][(top_idx[idx] + pos) % 8];
    return cur_tooth;
}

void rotate_gear(int idx, int dir){
    // 시계 방향
    if(dir == 1){
        top_idx[idx] = (top_idx[idx] - 1 + 8) % 8;
    }
    // 반시계 방향
    else{
        top_idx[idx] = (top_idx[idx] + 1) % 8;
    }
}

void func(){
    for(int t=0; t < K; t++){
        int dir[4] = {0, 0, 0, 0};
        int p, rd;
        cin >> p >> rd; p--;
        dir[p] = rd;

        // 좌측 톱니 처리
        for(int i=p-1; i >= 0; i--){
            if(tooth(i, 2) != tooth(i+1, 6)){
                dir[i] = -dir[i+1];
            }
            else break;
        }

        // 우측 톱니 처리
        for(int i=p+1; i < N; i++){
            if(tooth(i, 6) != tooth(i-1, 2)){
                dir[i] = -dir[i-1];
            }
            else break;
        }

        // 회전 처리
        for(int i=0; i < N; i++){
            if(dir[i] != 0){
                rotate_gear(i, dir[i]);
            }
        }
    }
    // 계산 처리
    int score = 0;
    for(int i=0; i < N; i++){
        if(gear[i][top_idx[i]] == 1){
            score += (1<<i);
        }
    }

    cout << score << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
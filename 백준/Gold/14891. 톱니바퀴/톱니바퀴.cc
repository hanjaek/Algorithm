#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int N = 4;
int K;
deque<int> gear[4];

void input(){
    for(int i=0; i < N; i++){
        string s;
        cin >> s;
        for(char ch : s){
            gear[i].push_back(ch -'0');
        }
    }
    cin >> K;
}

void rotate_gear(int idx, int dir){
    // 시계방향
    if(dir == 1){
        int back = gear[idx].back();
        gear[idx].pop_back();
        gear[idx].push_front(back);
    }
    // 반시계 방향
    else{
        int front = gear[idx].front();
        gear[idx].pop_front();
        gear[idx].push_back(front);
    }
}

void func(){
    for(int t=0; t < K; t++){
        int dir[4] = {0, 0, 0, 0};
        int p, rd;
        cin >> p >> rd; p--;
        
        dir[p] = rd;
        // 회전 톱니 기준 좌측 톱니들 처리
        for(int i = p-1; i >= 0; i--){
            if(gear[i][2] != gear[i+1][6]){
                dir[i] = -dir[i+1];
            }
            else break;
        }

        // 회전 톱니 기준 우측 톱니들 처리
        for(int i = p+1; i < N; i++){
            if(gear[i][6] != gear[i-1][2]){
                dir[i] = -dir[i-1];
            }
            else break;
        }

        // 회전 처리
        for(int i=0; i < N; i++){
            if(dir[i] != 0) rotate_gear(i, dir[i]);
        }
    }
    
    // 점수 처리
    int score = 0;
    for(int i=0; i < N; i++){
        if(gear[i][0] == 1){
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
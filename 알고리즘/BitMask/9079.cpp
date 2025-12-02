#include <iostream>
#include <algorithm>

using namespace std;

int T;
int mask[8];

void build_mask(){
    // 행 마스크
    mask[0] = (1<<0) | (1<<1) | (1<<2);
    mask[1] = (1<<3) | (1<<4) | (1<<5);
    mask[2] = (1<<6) | (1<<7) | (1<<8);

    // 열 마스크
    mask[3] = (1<<0) | (1<<3) | (1<<6);
    mask[4] = (1<<1) | (1<<4) | (1<<7);
    mask[5] = (1<<2) | (1<<5) | (1<<8);

    // 대각 마스크
    mask[6] = (1<<0) | (1<<4) | (1<<8);
    mask[7] = (1<<2) | (1<<4) | (1<<6);
}

int read_coin(){
    int state = 0;
    for(int r=0; r < 3; r++){
        for(int c=0; c < 3; c++){
            char coin;
            cin >> coin;

            int idx = r * 3 + c;
            // H는 비트 1로 표시
            if(coin == 'H') state |= (1<<idx);
        }
    }
    return state;
}

void input(){
    cin >> T;
}

void func(){
    build_mask();

    while(T--){
        int start = read_coin();
        int result = 1e9;

        for(int op=0; op < (1<<8); op++){
            int cur = start;
            int flip = 0;

            for(int k=0; k < 8; k++){
                if(op & (1<<k)){
                    cur ^= mask[k];
                    flip++;
                }
            }
            if(cur == 0 || cur == (1<<9) - 1){
                result = min(result, flip);
            }
        }
        cout << (result == 1e9 ? -1 : result) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
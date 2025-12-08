#include <iostream>

using namespace std;

#define MOD 1000000000

int N;
// [길이 수는 100 이하][끝자리는 0~9][0~9까지 사용을 비트로 표현]
int dp[101][10][1 << 10];

void input(){
    cin >> N;
}

void func(){
    // 한자리 수일 때 0은 안됨
    for(int last=1; last <= 9; last++){
        int mask = (1 << last);
        dp[1][last][mask] = 1;
    }

    for(int len = 1; len < N; len++){
        for(int last = 0; last <= 9; last++){
            for(int mask = 0; mask < (1 << 10); mask++){
                int cur = dp[len][last][mask];
                if(cur == 0) continue;

                if(last - 1 >= 0){
                    int next_digit = last - 1;
                    int next_mask = mask | (1 << next_digit);
                    int &ref = dp[len+1][next_digit][next_mask];
                    ref = (ref + cur) % MOD;
                }

                if(last + 1 <= 9){
                    int next_digit = last + 1;
                    int next_mask = mask | (1 << next_digit);
                    int &ref = dp[len+1][next_digit][next_mask];
                    ref = (ref + cur) % MOD;
                }
            }
        }
    }

    // 0~9까지 모두 사용한 계단 수 - used_all
    int used_all = (1 << 10) - 1;
    int result = 0;

    // 길이가 N이면서 0~9를 모두 사용한 계단 수 개수 찾기
    for(int last = 0; last <= 9; last++){
        result = (result + dp[N][last][used_all]) % MOD;
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
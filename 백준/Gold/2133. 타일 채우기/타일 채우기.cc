#include <iostream>

using namespace std;

int N;
int dp[31];

void input(){
    cin >> N;
}

void func(){
    if(N % 2 == 1){
        cout << 0 << "\n";
        return;
    }

    // N이 홀수면, 불가능. 
    // 3x2는 항상 3가지로 고정. 즉, 곱하기 3씩
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    // dp[3] = 0, dp[4] = 11
    // 4부터는 3x2로 고정된 블럭이 아니라 다른 패턴 2가지도 등장

    for(int i=4; i <= N; i += 2){
        dp[i] = dp[i-2] * 3;
        for(int j=i-4; j >= 0; j -= 2){
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[N] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
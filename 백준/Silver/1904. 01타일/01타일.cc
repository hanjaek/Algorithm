#include <iostream>
#include <vector>

using namespace std;

#define MOD 15746

int N;
vector <int> dp;

void input(){
    cin >> N;
    dp.resize(N+1);
}

void func(){
    dp[1] = 1;

    if(N >= 2) dp[2] = 2;

    for(int i=3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    cout << dp[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> dp;

void input(){
    cin >> N;
    dp.resize(max(3, N+1));
}

void func(){
    // 1, 1, 2, 3, 5, 8 ...

    dp[1] = 1;
    dp[2] = 1; 

    for(int i=3; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
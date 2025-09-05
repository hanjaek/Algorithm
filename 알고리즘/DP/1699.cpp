#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> dp;

void input(){
    cin >> N;
    dp.resize(N+1, 1e9);
}

void func(){
    dp[0] = 0;

    for(int i=1; i <= N; i++){
        for(int k=1; k*k <= i; k++){
            dp[i] = min(dp[i], dp[i - k*k] + 1);
        }
    }
    cout << dp[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
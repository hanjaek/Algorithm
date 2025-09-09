#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> coin, dp;

void input(){
    cin >> n >> k;
    coin.resize(n);
    dp.resize(k+1, 1e9);

    for(int i=0; i < n; i++){
        cin >> coin[i];
    }
}

void func(){
    dp[0] = 0;

    for(int c : coin){
        for(int i=c; i <= k; i++){
            dp[i] = min(dp[i], dp[i-c] + 1);
        }
    }

    cout << (dp[k] == 1e9 ? -1 : dp[k]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
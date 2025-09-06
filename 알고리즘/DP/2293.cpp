#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> coin;
vector<int> dp;

void input(){
    cin >> n >> k;
    coin.resize(n);
    dp.resize(k+1, 0);

    for(int i=0; i < n; i++){
        cin >> coin[i];
    }
}

void func(){
    dp[0] = 1;

    for(int c : coin){
        for(int i = c; i <= k; i++){
            dp[i] += dp[i - c];
        }
    }

    cout << dp[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
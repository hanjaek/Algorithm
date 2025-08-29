#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> drink, dp;

void input(){
    cin >> N;
    drink.resize(N+1);
    dp.resize(N+1, 0);

    for(int i=1; i <= N; i++){
        cin >> drink[i];
    }
}

void func(){
    dp[1] = drink[1];
    dp[2] = drink[1] + drink[2];

    for(int i=3; i <= N; i++){
        dp[i] = max({dp[i-1], dp[i-2] + drink[i],
        dp[i-3] + drink[i-1] + drink[i]});
    }

    cout << dp[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
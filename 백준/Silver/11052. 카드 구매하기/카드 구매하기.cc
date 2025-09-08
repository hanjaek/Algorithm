#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> card, dp;

void input(){
    cin >> N;
    card.resize(N); dp.resize(N+1, 0);

    for(int i=0; i < N; i++){
        cin >> card[i];
    }
}

void func(){
    for(int i=0; i <= N; i++){
        for(int j=1; j <= i; j++){
            dp[i] = max(dp[i], dp[i-j] + card[j-1]);
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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int coins[2] = {2, 5};
vector<int> dp;

void input(){
    cin >> N;
    dp.resize(N+1, 1e9);
}

void func(){
    dp[0] = 0;

    for(int i=1; i <= N; i++){
        for(int c : coins){
            if(i - c >= 0){
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }

    cout << (dp[N] == 1e9 ? -1 : dp[N]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
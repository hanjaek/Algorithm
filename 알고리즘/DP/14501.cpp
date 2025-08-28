#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> T, P, dp;

void input(){
    cin >> N;
    T.assign(N+2, 0);
    P.assign(N+2, 0);
    dp.assign(N+2, 0);

    for(int i=1; i <= N; i++){
        cin >> T[i] >> P[i];
    }
}

void func(){
    for(int i=N; i >= 1; i--){
        int next_day = i + T[i];
        if(next_day <= N+1){
            dp[i] = max(P[i] + dp[next_day], dp[i+1]);
        }
        else{
            dp[i] = dp[i+1];
        }
    }
    cout << dp[1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
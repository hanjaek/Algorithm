#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> W, V;
int dp[101][100001];

void input(){
    cin >> N >> K;
    W.resize(N+1); V.resize(N+1);

    for(int i=1; i <= N; i++){
        cin >> W[i] >> V[i];
    }
}

void func(){
    for(int i=1; i <= N; i++){
        for(int c=0; c <= K; c++){
            dp[i][c] = dp[i-1][c];
            if(c >= W[i]){
                dp[i][c] = max(dp[i][c], dp[i-1][c-W[i]] + V[i]);
            }
        }
    }

    cout << dp[N][K];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> wv;
vector<int> dp;

void input(){
    cin >> N >> K;
    wv.resize(N);
    dp.resize(K+1, 0);

    for(int i=0; i < N; i++){
        int w, v;
        cin >> w >> v;
        wv[i] = {w, v};
    }
}

void func(){
    for(int i=0; i < N; i++){
        int cw = wv[i].first;
        int cv = wv[i].second;

        for(int c=K; c >= cw; c--){
            dp[c] = max(dp[c], dp[c-cw] + cv);
        }
    }
    cout << dp[K];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
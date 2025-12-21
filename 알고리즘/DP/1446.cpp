#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, D;
vector<vector<pair<int, int>>> shortcuts;
vector<int> dp;

void input(){
    cin >> N >> D;
    shortcuts.resize(D+1);
    dp.resize(D+1, 1e9);

    for(int i=0; i < N; i++){
        int start, end, len;
        cin >> start >> end >> len;

        if(end > D) continue;
        if(len >= (end - start)) continue;
        if(start < 0 || start > D) continue;

        shortcuts[start].push_back({end, len});
    }
}

void func(){
    dp[0] = 0;

    for(int i=0; i <= D; i++){
        if(i > 0){
            dp[i] = min(dp[i], dp[i-1] + 1);
        }

        for(auto &sh : shortcuts[i]){
            int end = sh.first;
            int len = sh.second;
            dp[end] = min(dp[end], dp[i] + len);
        }
    }
    cout << dp[D] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
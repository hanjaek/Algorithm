#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> wires;
vector<int> dp;

void input(){
    cin >> N;
    wires.resize(N);
    dp.resize(N, 1);

    for(int i=0; i < N; i++){
        cin >> wires[i].first >> wires[i].second;
    }
}

void func(){
    int lis_len = 1;
    sort(wires.begin(), wires.end());
    
    for(int i=0; i < N; i++){
        for(int j=0; j < i; j++){
            if(wires[j].second < wires[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis_len = max(lis_len, dp[i]);
    }
    cout << N - lis_len << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
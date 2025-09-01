#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> dp;

void input(){
    cin >> N; 
    dp.resize(max(4, N+1), 0);
}

void func(){
    dp[1] = 1; dp[2] = 0; dp[3] = 1;
    
    for(int i=4; i <= N; i++){
        dp[i] = (!dp[i-1]) || (!dp[i-3]);
    }
    cout << (dp[N] ? "SK" : "CY");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> L, J, dp;

void input(){
    cin >> N;
    L.resize(N);
    J.resize(N);
    dp.resize(100, 0);

    for(int i=0; i < N; i++){
        cin >> L[i];
    }
    for(int i=0; i < N; i++){
        cin >> J[i];
    }
}

void func(){
    for(int i=0; i < N; i++){
        int hp = L[i];
        int happy = J[i];

        for(int h = 99; h >= hp; h--){
            dp[h] = max(dp[h], dp[h-hp] + happy);
        }
    }
    cout << dp[99] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
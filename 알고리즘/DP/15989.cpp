#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n;
vector<int> dp;

void input(){
    cin >> n;
}

void func(){
    dp.assign(n+1, 0);
    int numbers[3] = {1, 2, 3};
    dp[0] = 1;

    for(int num: numbers){
        for(int i=num; i <= n; i++){
            dp[i] += dp[i - num];
        }
    }
    cout << dp[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while(T--){
        input();
        func();
    }
}
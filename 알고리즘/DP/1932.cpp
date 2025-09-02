#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> tri;
vector<int> dp;


void input(){
    cin >> N;
    tri.resize(N, {});
    dp.resize(N, 0);

    for(int i=0; i < N; i++){
        tri[i].resize(i+1);
        for(int j=0; j <= i; j++){
            cin >> tri[i][j];
        }
    }
}

void func(){
    dp[0] = tri[0][0];

    for(int i=1; i < N; i++){
        for(int j=i; j >= 0; j--){
            if(j == 0){
                dp[j] = dp[j] + tri[i][j];
            }
            else if(j == i){
                dp[j] = dp[j-1] + tri[i][j];
            }
            else{
                dp[j] = max(dp[j-1], dp[j]) + tri[i][j];
            }
        }
    }

    cout << *max_element(dp.begin(), dp.begin() + N);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string A, B;
vector<vector<int>> dp;

void input(){
    cin >> A >> B;
}

void func(){
    int n = (int)A.size();
    int m = (int)B.size();
    dp.resize(n+1, vector<int>(m+1, 0));

    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
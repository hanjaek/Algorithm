#include <string>
#include <vector>

#define MOD 1000000007
using namespace std;

void init_dp(vector<vector<int>> &DP, vector<vector<int>> &puddles, int m, int n){
    DP[0][0] = 1;
    
    for(auto p : puddles){
        int x = p[0] - 1;
        int y = p[1] - 1;
        
        DP[y][x] = -1;
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> DP(n, vector<int>(m, 0));
    
    init_dp(DP, puddles, m, n);
    
    for(int y=0; y < n; y++){
        for(int x=0; x < m; x++){
            if(DP[y][x] == -1){
                DP[y][x] = 0;
                continue;
            }
            
            if(x > 0){
                DP[y][x] = (DP[y][x] + DP[y][x-1]) % MOD;
            }
            if(y > 0){
                DP[y][x] = (DP[y][x] + DP[y-1][x]) % MOD;
            }
        }
    }
    
    return DP[n-1][m-1];
}
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;
    
    int DP[1000001]={0};
    
    for(int i=2; i <= N; i++){

        if(i % 6 == 0){
            int min_dp = min(min(DP[i/3] + 1, DP[i/2] + 1), DP[i-1] + 1);
            DP[i] = min_dp;
        }
        else if(i % 3 == 0){
            DP[i] = min(DP[i/3] + 1, DP[i-1] + 1);
        }
        else if(i % 2 ==0){
            DP[i] = min(DP[i/2] + 1, DP[i-1] + 1);
        }
        else{
            DP[i] = DP[i-1] + 1;
        }
    }
    
    cout << DP[N];

}
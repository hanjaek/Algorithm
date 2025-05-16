#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T, N;
    cin >> T;
    
    for(int i=0; i < T; i++){

        int DP_zero[41] = {0};
        int DP_one[41] = {0};
        DP_zero[0] = 1; DP_one[0] = 0;
        DP_zero[1] = 0; DP_one[1] = 1;

        cin >> N;

        for(int i=2; i <= N; i++){
            DP_zero[i] = DP_zero[i-1] + DP_zero[i-2];
            DP_one[i] = DP_one[i-1] + DP_one[i-2];
        }
        
        cout << DP_zero[N] << " " << DP_one[N] << "\n";

    }

}
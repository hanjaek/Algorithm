#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, number;
    int DP[11]={0};

    DP[1] = 1; DP[2] = 2; DP[3] = 4;

    cin >> T;
    for(int i=4; i < 11; i++){
        DP[i] = DP[i-3] + DP[i-2] + DP[i-1];
    }
    for(int i=0; i < T; i++){
        cin >> number;
        cout << DP[number] << "\n";
    }

}
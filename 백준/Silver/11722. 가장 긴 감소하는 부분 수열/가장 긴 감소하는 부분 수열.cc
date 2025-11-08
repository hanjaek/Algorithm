#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> dp;

void input(){
    cin >> N;
    A.resize(N);
    dp.resize(N, 1);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    int result = (N > 0 ? 1 : 0);

    for(int i=1; i < N; i++){
        for(int j=0; j < i; j++){
            if(A[j] > A[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
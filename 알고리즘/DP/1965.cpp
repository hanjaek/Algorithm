#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> box;
vector<int> dp;

void input(){
    cin >> n;
    box.resize(n);
    dp.resize(n, 1);

    for(int i=0; i < n; i++){
        cin >> box[i];
    }
}

void func(){
    int result = 1;

    for(int i=1; i < n; i++){
        for(int j=0; j < i; j++){
            if(box[j] < box[i]){
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
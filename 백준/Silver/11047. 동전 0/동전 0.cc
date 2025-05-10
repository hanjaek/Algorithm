#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, K; // N: 동전 가치, K: 만들 금액
    cin >> N >> K;
    int cnt = 0;

    vector<int> money(N);
    for(int i=0; i < N; i++){
        cin >> money[i];
    }

    for(int i = money.size()-1; i >= 0; i--){
        cnt += K/money[i];
        K %= money[i];
    }

    cout << cnt;
}
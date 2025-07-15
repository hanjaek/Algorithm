#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> P;

void input(){
    cin >> N >> M;
    P.resize(M);
    for(int i=0; i < M; i++){
        cin >> P[i];
    }
}

void func(){
    sort(P.begin(), P.end(), greater<>());
    int max_M = 0, max_P = 0;

    for(int i=0; i < M; i++){
        int cnt = min(N, i+1);
        int income = P[i] * cnt;

        if(income > max_M){
            max_M = income;
            max_P = P[i];
        }
    }
    cout << max_P << " " << max_M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
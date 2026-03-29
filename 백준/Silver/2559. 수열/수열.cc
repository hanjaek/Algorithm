#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N, K;
vector<int> temper;

void input(){
    cin >> N >> K;
    temper.resize(N);

    for(int i=0; i < N; i++){
        cin >> temper[i];
    }
}

void func(){
    int result, sum = 0;

    for(int i=0; i < K; i++){
        sum += temper[i];
    }
    result = sum;

    for(int i=K; i < N; i++){
        sum += temper[i];
        sum -= temper[i-K];

        result = max(result, sum);
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}
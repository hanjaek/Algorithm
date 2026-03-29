#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define endl "\n"
#define ll long long

int N, K;
vector<int> A;

void input(){
    cin >> N >> K;
    A.resize(N);
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}

void func(){
    ll result = 0, sum = 0;

    map<int, int> cnt;
    cnt[0] = 1;

    for(int i=0; i < N; i++){
        sum += A[i];

        result += cnt[sum - K];
        cnt[sum]++;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}
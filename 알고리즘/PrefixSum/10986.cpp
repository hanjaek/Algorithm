#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;
#define endl "\n"
#define ll long long

int N, M;
vector<int> A;
vector<ll> cnt;

void input(){
    cin >> N >> M;
    A.resize(N);
    cnt.resize(M, 0);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    ll result = 0, sum = 0;
    int r = 0;
    cnt[r] = 1;

    for(int i=0; i < N; i++){
        sum += A[i];
        r = sum % M;

        result += cnt[r];
        cnt[r]++;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
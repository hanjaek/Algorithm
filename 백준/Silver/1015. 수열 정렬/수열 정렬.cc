#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> A;
vector<int> P;

void input(){
    cin >> N;
    A.resize(N);
    P.resize(N);

    for(int i=0; i < N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
}

void func(){
    sort(A.begin(), A.end());

    for(int i=0; i < N; i++){
        P[A[i].second] = i;
    }
    for(int i=0; i < N; i++){
        cout << P[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
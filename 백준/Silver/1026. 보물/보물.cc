#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

void input(){
    cin >> N;
    A.resize(N); B.resize(N);
    for(int i=0; i < N; i++){ cin >> A[i]; }
    for(int i=0; i < N; i++){ cin >> B[i]; }
}

void func(){
    int result = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    for(int i=0; i < N; i++){
        result += A[i] * B[i];
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
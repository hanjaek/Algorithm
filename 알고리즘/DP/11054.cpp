#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> L, R;

void input(){
    cin >> N;
    A.resize(N);
    L.resize(N, 1); R.resize(N, 1);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    int result = 0;

    for(int i=0; i < N; i++){
        for(int j=0; j < i; j++){
            if(A[i] > A[j]){
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }

    for(int i=N-1; i >= 0; i--){
        for(int j=N-1; j > i; j--){
            if(A[i] > A[j]){
                R[i] = max(R[i], R[j] + 1);
            }
        }
    }

    for(int i=0; i < N; i++){
        result = max(result, L[i] + R[i] -1);
    }

    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<int> B;

void input(){
    cin >> N;
    A.resize(N);
    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    B.resize(N);
    int sum = 0;

    for(int i=0; i < N; i++){
        sum += (i % 2 == 0 ? A[i] : -A[i]);
    }
    B[0] = sum / 2;

    for(int i=1; i < N; i++){
        B[i] = A[i-1] - B[i-1];
    }
    for(int i=0; i < N; i++){
        cout << B[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
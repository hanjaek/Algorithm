#include <iostream>
#include <vector>

using namespace std;

int N, L, R, X;
vector<int> A;
// L <= 문제 난이도 합 <= R
// X <= 어려운 난이도 - 쉬운 난이도

void input(){
    cin >> N >> L >> R >> X;
    A.resize(N);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    int result = 0;

    for(int mask = 1; mask < (1 << N); mask++){
        int sum = 0;
        int cnt = 0;
        int min_A = 1e9;
        int max_A = 0;
        
        for(int i=0; i < N; i++){
            if(mask & (1 << i)){
                sum += A[i];
                cnt++;
                if(A[i] > max_A) max_A = A[i];
                if(A[i] < min_A) min_A = A[i];
            }
        }
        if(cnt >= 2 && L <= sum && sum <= R && (max_A - min_A) >= X){
            result++;
        }
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
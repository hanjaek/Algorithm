#include <iostream>

using namespace std;

int N, M, K;

void input(){
    cin >> N >> M >> K;
}

double comb(int n, int r){
    double result = 1;
    for(int i=0; i < r; i++){
        result *= (n-i);
        result /= (i+1);
    }
    return result;
}

void func(){
    double total = comb(N, M);
    double success = 0;

    for(int i=K; i <= M; i++){
        if(M < i || N - M < M - i) continue;
        success += comb(M,i) * comb(N-M, M-i);
    }

    cout.precision(10);
    cout << fixed << success / total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
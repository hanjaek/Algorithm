#include <iostream>

using namespace std;

int N, K;

void input(){
    cin >> N >> K;
}

int bitcount(int x){
    int cnt = 0;
    while(x > 0){
        if(x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

void func(){
    int result = 0;

    if(N <= K){
        cout << 0 << "\n";
        return;
    }

    while(bitcount(N) > K){
        // 가장 최소 비트 값을 구할 때, N & -N하면 그 값이 나옴
        // 최소 비트 값 만큼 상점에서 구매해야함
        // 그리고 병합
        int lsb = N & -N; 
        result += lsb;
        N += lsb;
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
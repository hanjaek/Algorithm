#include <iostream>

using namespace std;

long long N;

void input(){
    cin >> N;
}

void func(){
    long long result = 0;
    long long prod = 1;

    while(N > 0){
        if(N & 1LL){
            result += prod;
        }
        prod *= 3;
        N = N >> 1;
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
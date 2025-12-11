#include <iostream>

using namespace std;

long long X, K;

void input(){
    cin >> X >> K;
}

void func(){
    long long x = X;
    long long k = K;
    long long y = 0;
    long long pos = 0;

    while(x > 0 || k > 0){
        if((x & 1LL) == 0){
            if(k & 1LL){
                y |= (1LL << pos);
            }
            k >>= 1;
        }
        x >>= 1;
        pos++;
    }
    cout << y << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}

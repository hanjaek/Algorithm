#include <iostream>

using namespace std;

int A, B, C, D;

int gcd(int a, int b){
    while(b!=0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void input(){
    cin >> A >> B;
    cin >> C >> D;
}

void func(){
    int numer = A * D + B * C;
    int denom = B * D;

    int gc = gcd(numer, denom);
    numer /= gc;
    denom /= gc;

    cout << numer << " " << denom;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
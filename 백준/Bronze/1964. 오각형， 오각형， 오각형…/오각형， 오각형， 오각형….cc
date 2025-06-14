#include <iostream>

using namespace std;

#define MOD 45678
int n;

void input(){
    cin >> n;
}

void func(){
    long long result = (3LL * n * n + 5LL * n + 2) / 2;
    result %= MOD;
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
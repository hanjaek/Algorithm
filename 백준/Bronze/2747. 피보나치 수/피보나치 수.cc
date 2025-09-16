#include <iostream>
#include <vector>

using namespace std;

int n;
long long fib[46];

void input(){
    cin >> n;
}

void func(){
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout << fib[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
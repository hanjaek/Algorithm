#include <iostream>

using namespace std;

long long A, B;

void input(){
    cin >> A >> B;
}

void func(){
    if(A > B){
        swap(A, B);
    }

    long long n = B - A + 1;
    long long result = n * (A+B) / 2;

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
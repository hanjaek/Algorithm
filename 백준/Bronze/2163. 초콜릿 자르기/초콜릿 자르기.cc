#include <iostream>

using namespace std;

int N, M;

void input(){
    cin >> N >> M;
}

void func(){
    cout << N * M - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
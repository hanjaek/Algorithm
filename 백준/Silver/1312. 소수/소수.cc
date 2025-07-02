#include <iostream>

using namespace std;

int A, B, N;

void input(){
    cin >> A >> B >> N;
}

void func(){
    int remain = A % B;
    for(int i=0; i < N-1; i++){
        remain = (remain * 10) % B;
    }
    remain = (remain * 10) / B;
    cout << remain;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>

using namespace std;

int N, A, B;

void input(){
    cin >> N >> A >> B;
}

void func(){
    int cnt = 0;
    while(A != B){
        A = (A+1) / 2;
        B = (B+1) / 2;
        cnt++;
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
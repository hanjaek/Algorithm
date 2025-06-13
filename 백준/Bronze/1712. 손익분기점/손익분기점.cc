#include <iostream>

using namespace std;

long long A, B, C;
// 총 지출 A + Bx, 총 수익 Cx -> Cx > A + Bx가 되는 시점의 x > A / C - B  즉 , A / C - B가 3이면 x는 4

void input(){
    cin >> A >> B >> C;
}

void func(){
    if(B >= C){
        cout << -1;
    }
    else{
        long long cnt = A / (C - B) + 1;
        cout << cnt;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
#include <iostream>

using namespace std;

int x;

void input(){
    cin >> x;
}

void func(){
    int cnt = 0;
    while(x > 0){
        if(x % 2 == 1) cnt++;
        x /= 2;
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
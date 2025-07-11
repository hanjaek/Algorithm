#include <iostream>

using namespace std;

int N;

bool check(int number){
    if (number < 100) return true;

    int a = number / 100;
    int b = (number / 10) % 10;
    int c = number % 10;

    return (a - b) == (b - c);
}

void input(){
    cin >> N;
}

void func(){
    int cnt = 0;
    for(int i=1; i <= N; i++){
        if(check(i)) cnt++;
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
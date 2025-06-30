#include <iostream>

using namespace std;

int x;

// 짝수 대각 - 분모 감소, 분자 증가
// 홀수 대각 - 분모 증가, 분자 감소

void input(){
    cin >> x;
}

void func(){
    int deno, nume;
    int line = 1;
    int tmp = x;

    // x가 몇 번째 대각선인지
    while(tmp > line){
        tmp -= line;
        line++;
    }

    if(line % 2 == 0){
        nume = tmp;
        deno = line - tmp + 1;
    }
    else{
        nume = line - tmp + 1;
        deno = tmp;
    }
    cout << nume << "/" << deno;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
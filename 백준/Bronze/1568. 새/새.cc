#include <iostream>

using namespace std;

int N;

void input(){
    cin >> N;
}

void func(){
    int result = 0;
    int num = 1;

    while(N!=0){
        if(num > N){
            num = 1;
        }
        N -= num;
        num++;
        result++;
    }

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
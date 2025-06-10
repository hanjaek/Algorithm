#include <iostream>

using namespace std;

int N, m, M, T, R;

void input(){
    cin >> N >> m >> M >> T >> R;
}

void func(){
    if(m + T > M){
        cout << -1;
        exit(0);
    }
    int cur = m;
    int time = 0;
    int exer = 0;

    while(exer < N){
        if(cur + T <= M){
            cur += T;
            exer++;
        }
        else{
            cur -= R;
            if(cur <m){
                cur = m;
            }
        }
        time++;
    }
    cout << time;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
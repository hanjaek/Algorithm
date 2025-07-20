#include <iostream>
#include <algorithm>

using namespace std;

int N, T;

void input(){
    cin >> N >> T;
}

void func(){
    int min_wait = 1e9;

    for(int i=0; i < N; i++){
        int S, I, C;
        cin >> S >> I >> C;

        for(int j=0; j < C; j++){
            int arrival = S + I * j;
            if(arrival >= T){
                min_wait = min(min_wait, arrival - T);
                break;
            }
        }
    }
    if(min_wait == 1e9){
        cout << -1;
    }
    else{
        cout << min_wait;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
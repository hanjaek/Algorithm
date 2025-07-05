#include <iostream>

using namespace std;

int cnt[10] = {0};
string numbers;

void input(){
    cin >> numbers;
}

void func(){
    for(char element : numbers){
        cnt[element - '0']++;
    }

    cnt[6] = (cnt[6] + cnt[9] + 1) / 2;
    cnt[9] = 0;

    int max = 0;
    for(int i=0; i < 9; i++){
        if(cnt[i] > max){
            max = cnt[i];
        }
    }
    cout << max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
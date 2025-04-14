#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;
    int cnt = 0;
    int t = 1;

    if(N==1){
        cout << 1;
        return 0;
    }

    cnt ++;

    for(int i=1; t < N; i++){
        cnt++;
        t += i * 6;
    }

    cout << cnt;
}
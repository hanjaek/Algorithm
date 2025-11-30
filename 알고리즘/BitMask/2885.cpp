#include <iostream>

using namespace std;

int K;

void input(){
    cin >> K;
}

void func(){
    int choco = 1;
    int cut = 0;

    while(choco < K){
        choco *= 2;
    }

    int size = choco;
    while(K % choco != 0){
        choco /= 2;
        cut++;
    }
    cout << size << " " << cut << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
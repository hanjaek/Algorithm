#include <iostream>

using namespace std;
#define endl "\n"

int A[10], B[10];

void input(){
    for(int i=0; i < 10; i++){
        cin >> A[i];
    }
    for(int i=0; i < 10; i++){
        cin >> B[i];
    }
}

void func(){
    int A_win = 0, B_win = 0;

    for(int i=0; i < 10; i++){
        if(A[i] > B[i]) A_win++;
        else if(A[i] < B[i]) B_win++;
    }

    cout << (A_win > B_win ? 'A' : (A_win < B_win ? 'B' : 'D')) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
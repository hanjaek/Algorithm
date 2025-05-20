#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    long long P[101] = {0}; // int 하니까 틀림 P(N)이 int 범위를 초과하게 됨
    P[1]=1; P[2]=1; P[3]=1; 

    for(int i=4; i <= 100; i++){
        P[i] = P[i-2] + P[i-3];
    }

    cin >> T;

    for(int i=0; i < T; i++){
        cin >> N;
        cout << P[N] << "\n";
    }

}
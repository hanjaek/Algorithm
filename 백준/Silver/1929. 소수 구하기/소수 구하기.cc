#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;
    
    vector<bool> is_prime(M+1, true);
    is_prime[1] = false;

    for(int i=2; i <= M; i++){
        if(is_prime[i]){
            for(int j = i*2; j <= M; j+=i){
                is_prime[j] = false;
            }
        }
    }

    for(int i=N; i <= M; i++){
        if(is_prime[i]){
            cout << i << "\n";
        }
    }

}
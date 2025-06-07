#include <iostream>
#include <cmath>

using namespace std;

int N, M;

bool is_prime(int num){
    if(num < 2) return false;

    for(int i=2; i*i <= num; i++){
        if(num % i == 0) return false;
    }
    
    return true;
}

void input(){
    cin >> N >> M;
}

void func(){
    long long result = 0;
    int min_prime = 1e9;

    for(int i=N; i <= M; i++){
        if(is_prime(i)){
            result += i;
            if(min_prime > i){
                min_prime = i;
            }
        }
    }

    if(result == 0) {
        cout << -1;
    }
    else{
        cout << result << '\n' << min_prime;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
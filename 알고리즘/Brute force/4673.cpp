#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

int digit_sum(int n){
    int sum = n;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void func(){
    vector<bool> make(MAX+1, false);

    for(int n=1; n <= MAX; n++){
        int value = digit_sum(n);
        if(value <= MAX){
            make[value] = true;
        } 
    }
    for(int n=1; n <= MAX; n++){
        if(!make[n]) cout << n << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input();
    func();
}
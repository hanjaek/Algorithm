#include <iostream>

using namespace std;

long long number;
long long sum;
int result;

void input(){
    cin >> number;
}

void func(){
    for(int i=1; ;i++){
        if(sum + i > number) break;
        sum += i;
        result++;
    }

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}


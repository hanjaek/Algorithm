#include <iostream>
#include <cmath>

using namespace std;

int N;

void input(){
    cin >> N;
}

void func(){
    int result = 0;
    int length = 1;
    int start = 1;
    int end = 9;

    while(N >= start){
        int upper = min(N, end);
        result += (upper - start + 1) * length;
        length++;
        start *= 10;
        end = end * 10 + 9;
    }

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}

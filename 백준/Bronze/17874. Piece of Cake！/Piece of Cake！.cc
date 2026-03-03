#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"

int N, H, V;

void input(){
    cin >> N >> H >> V;
}

void func(){
    int result = max({V*H, (N-V)*H, (N-H)*V, (N-H)*(N-V)});
    cout << result * 4 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
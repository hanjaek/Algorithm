#include <iostream>
#include <string>

using namespace std;

int N;
string K;

void input() {
    cin >> N;  
    cin >> K;  
}

void func() {
    int cnt = 0;
    for (char c : K) {
        if (c == '1') cnt++; 
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
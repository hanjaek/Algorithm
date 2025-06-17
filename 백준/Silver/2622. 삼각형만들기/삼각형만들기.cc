#include <iostream>

using namespace std;

int N, result = 0;

void input() {
    cin >> N;
}

void func() {
    for (int a = 1; a <= N; ++a) {
        for (int b=a; b <= N - a; b++) {
            int c = N-(a+b);
            if (c < b) continue;  
            if (a + b > c) result++;  
        }
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}

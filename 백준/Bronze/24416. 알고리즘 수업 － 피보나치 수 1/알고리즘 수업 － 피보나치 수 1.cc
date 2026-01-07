#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;

void input() {
    cin >> n;
    dp.resize(n+1, 0);
}

void func() {
    dp[1] = 1;
    if (n >= 2) dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << " " << (n - 2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}

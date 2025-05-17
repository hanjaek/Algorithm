#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int score[301] = {0};
    int DP[301] = {0};

    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    DP[0] = score[0];
    DP[1] = score[0] + score[1];
    DP[2] = max(score[0] + score[2], score[1] + score[2]);

    for (int i = 3; i < N; i++) {
        DP[i] = max(DP[i - 2], DP[i - 3] + score[i - 1]) + score[i];
    }

    cout << DP[N-1];

}

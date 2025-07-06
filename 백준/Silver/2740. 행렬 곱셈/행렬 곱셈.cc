#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> A, B, C;

void input() {
    cin >> N >> M;
    A.resize(N, vector<int>(M));
    for (int i=0; i < N; i++)
        for (int j=0; j < M; j++)
            cin >> A[i][j];

    int row;
    cin >> row >> K; 
    B.resize(row, vector<int>(K));
    for (int i=0; i < row; i++)
        for (int j = 0; j < K; j++)
            cin >> B[i][j];
}

void func() {
    C.resize(N, vector<int>(K, 0));
    for (int i=0; i < N; i++) {
        for (int j=0; j < K; j++) {
            for (int k=0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i=0; i < N; i++) {
        for (int j=0; j < K; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}

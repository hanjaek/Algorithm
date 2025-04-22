#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    map<int, bool> check;

    cin >> N;
    vector<int> A(N);

    for(int i=0; i < N; i++){
        cin >> A[i];
        check[A[i]] = true;
    }

    cin >> M;
    vector<int> B(M);

    for(int i=0; i < M; i++){
        cin >> B[i];
    }

    for(auto element : B){

        int result = check[element] ? 1 : 0;
        cout << result << "\n";

    }
    

}
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A;

void input(){
    cin >> N >> M;
    A.resize(N);
    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    int cnt = 0;

    for(int i=0; i < N; i++){
        int sum = 0;
        for(int j=i; j < N; j++){
            sum += A[j];
            if(sum == M){
                cnt++;
                break;
            }
            else if(sum > M){
                break;
            }
        }
    }

    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
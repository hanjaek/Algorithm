#include <iostream>
#include <vector>

using namespace std;

int N, B, C;
vector<int> A;

void input(){
    cin >> N;
    A.resize(N);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
    cin >> B >> C;
}

void func(){
    long long cnt = 0;

    for(int element : A){
        element -= B;
        cnt++;
        if(element > 0){
            cnt += (element + C - 1) / C;
        }
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
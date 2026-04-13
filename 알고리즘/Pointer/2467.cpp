#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define endl "\n"

int N;
vector<int> A;

void input(){
    cin >> N;
    A.resize(N);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    pair<int, int> result;
    int sum = 2e9;
    int i=0, j=N-1;

    while(i < j){
        int cur = A[i]+A[j];

        if(abs(cur) < sum){
            sum = abs(A[i]+A[j]);
            result = {A[i], A[j]};
        }

        if(cur < 0){
            i++;
        }
        else if(cur > 0){
            j--;
        }
        else break;
    }
    cout << result.first << " " << result.second << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
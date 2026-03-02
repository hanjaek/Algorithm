#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"

int N;
vector<int> scores;

void input(){
    cin >> N;
    scores.resize(N);

    for(int i=0; i < N; i++){
        cin >> scores[i];
    }
}

void func(){
    int result = 0;

    for(int i=N-1; i > 0; i--){
        while(scores[i-1] >= scores[i]){
            scores[i-1]--;
            result++;
        }
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}
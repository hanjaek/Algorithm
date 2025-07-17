#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, score, P;
vector<int> scores;

void input(){
    cin >> N >> score >> P;
    scores.resize(N);
    for(int i=0; i < N; i++){
        cin >> scores[i];
    }
}

void func(){
    int rank = 1;

    scores.push_back(score);
    sort(scores.begin(), scores.end(), greater<>());

    for(int i=0; i < scores.size(); i++){
        if(scores[i] > score) rank++;
        else break;
    }

    if(N == P && scores[P] == score){
        cout << -1;
    }
    else{
        cout << rank;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}
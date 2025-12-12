#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<pair<int ,int>> scores;

void input(){
    cin >> N;
    scores.resize(N);

    for(int i=0; i < N; i++){
        cin >> scores[i].first >> scores[i].second;
    }
}

void func(){
    int selection = 0;

    sort(scores.begin(), scores.end());
    int min_rank = scores[0].second;
    selection++;

    for(int i=1; i < N; i++){
        if(scores[i].second < min_rank){
            selection++;
            min_rank = min(min_rank, scores[i].second);
        }
    }

    cout << selection << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while(T--){
        input();
        func();
    }
}
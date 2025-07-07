#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> scores;
vector<int> selected;
int sum = 0;

void input(){
    for(int i=1; i <= 8; i++){
        int score;
        cin >> score;
        scores.push_back({score, i});
    }
}

void func(){
    sort(scores.begin(), scores.end());

    for(int i=3; i < 8; i++){
        sum += scores[i].first;
        selected.push_back(scores[i].second);
    }
    
    sort(selected.begin(), selected.end());

    cout << sum << "\n";
    for(int element : selected){
        cout << element << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}